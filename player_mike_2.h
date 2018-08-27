#ifndef _PLAYER_MIKE_2_H_
#define _PLAYER_MIKE_2_H_

#include <string>
#include <iomanip>
#include <stdlib.h>
#include "player.h"

// This is an awesome player: It magically
// predicts what the opponent will play!

class PlayerMike_2 : public Player
{
public:
   PlayerMike_2(const std::string& name) :
      Player(name),
      m_histSize(2),
      m_predictMe(3),
      m_predictYou(3)
   {}

   int move(const std::vector<Move>& moveHistory)
   {
      if (!moveHistory.empty())
      {
         // Attempt to predict the opponents strategy
         fillPredict(moveHistory);

         // Select randomly a predicted strategy
         int s = selectStrategy();

         switch (s)
         {
            case 0 :
#ifdef DEBUG
               std::cout << "COPY" << std::endl;
#endif

               // Opponent will try to copy my last move
               // We will play whatever beats our last move
               return beats(moveHistory.back().m_me);

            case 1 :
#ifdef DEBUG
               std::cout << "NEXT" << std::endl;
#endif

               // Opponent will try to beat my last move
               // We will play whatever beats that
               return beats(beats(moveHistory.back().m_me));

            case 2 :
#ifdef DEBUG
               std::cout << "CONST" << std::endl;
#endif

               // Opponent is a loser
               // We'll just play whatever beats his last move
               return beats(moveHistory.back().m_you);

            case 3 :
#ifdef DEBUG
               std::cout << "CYCLE UP" << std::endl;
#endif

               // Opponent is cycling upwards
               // We'll just play whatever beats his next move
               return beats(beats(moveHistory.back().m_you));

            case 4 :
#ifdef DEBUG
               std::cout << "CYCLE DOWN" << std::endl;
#endif

               // Opponent is cycling downwards
               // We'll just play whatever beats his next move
               return moveHistory.back().m_you;
         }
      }

      return rand() % 3;

   } // end of int move

private:
   void fillPredict(const std::vector<Move>& moveHistory)
   {
      m_predictMe[0] = 1.0/3.0;   // COPY
      m_predictMe[1] = 1.0/3.0;   // NEXT
      m_predictMe[2] = 1.0/3.0;   // CONST

      m_predictYou[0] = 1.0/3.0;   // CONST
      m_predictYou[1] = 1.0/3.0;   // CYCLE
      m_predictYou[2] = 1.0/3.0;   // CYCLE

      for (size_t i=1; i<moveHistory.size(); ++i)
      {
         // We compare the opponents last move, with our previous move,
         // to determine the opponents dominant strategy.
         int s = (moveHistory[i].m_you - moveHistory[i-1].m_me + 3) % 3;

         m_predictMe[0] *= 1.0 - 1.0/m_histSize;
         m_predictMe[1] *= 1.0 - 1.0/m_histSize;
         m_predictMe[2] *= 1.0 - 1.0/m_histSize;
         m_predictMe[s] += 1.0/m_histSize;

         // We compare the opponents last move, with our previous move,
         // to determine the opponents dominant strategy.
         s = (moveHistory[i].m_you - moveHistory[i-1].m_you + 3) % 3;

         m_predictYou[0] *= 1.0 - 1.0/i;
         m_predictYou[1] *= 1.0 - 1.0/i;
         m_predictYou[2] *= 1.0 - 1.0/i;
         m_predictYou[s] += 1.0/i;
      }

#ifdef DEBUG
      std::cout << "Predictions (you) : "
         << std::fixed << std::setw(4) << std::setprecision(2) << m_predictYou[0] << " , "
         << std::fixed << std::setw(4) << std::setprecision(2) << m_predictYou[1] << " , "
         << std::fixed << std::setw(4) << std::setprecision(2) << m_predictYou[2] << " = "
         << std::fixed << std::setw(4) << std::setprecision(2) << m_predictYou[0] + m_predictYou[1] + m_predictYou[2] << std::endl;
      std::cout << "Predictions (me)  : "
         << std::fixed << std::setw(4) << std::setprecision(2) << m_predictMe[0] << " , "
         << std::fixed << std::setw(4) << std::setprecision(2) << m_predictMe[1] << " , "
         << std::fixed << std::setw(4) << std::setprecision(2) << m_predictMe[2] << " = "
         << std::fixed << std::setw(4) << std::setprecision(2) << m_predictMe[0] + m_predictMe[1] + m_predictMe[2] << " -> ";
#endif
   }

   int selectStrategy()
   {
      if (m_predictYou[0] > 0.9)
         return 2; // LOSER

      if (m_predictYou[1] > 0.9)
         return 3; // CYCLE UP

      if (m_predictYou[2] > 0.9)
         return 4; // CYCLE DOWN

      float x = (float)rand()/(float)(RAND_MAX);

      if (x < m_predictMe[0])
         return 0;
      if (x < m_predictMe[0] + m_predictMe[1])
         return 1;
      return 2;
   }

private:
   int m_histSize;
   std::vector<float> m_predictMe;
   std::vector<float> m_predictYou;

}; // end of PlayerMike_2

#endif // _PLAYER_MIKE_2_H_

