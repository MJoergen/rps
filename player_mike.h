#ifndef _PLAYER_MIKE_H_
#define _PLAYER_MIKE_H_

#include <string>
#include <stdlib.h>
#include "player.h"

// This is an awesome player: It magically
// predicts what the opponent will play!

class PlayerMike : public Player
{
public:
   PlayerMike(const std::string& name) :
      Player(name)
   {}

   int move(const std::vector<Move>& moveHistory)
   {
      // The first move, just play a random move.
      if (moveHistory.size() == 0)
      {
         return rand() % 3;
      }

      // The next nine moves, just play whatever beats the opponents last move.
      if (moveHistory.size() < 10)
      {
         return beats(moveHistory[moveHistory.size()-1].m_you);
      }

      // If last game was a draw
      if (moveHistory[moveHistory.size()-1].m_me == moveHistory[moveHistory.size()-1].m_you)
      {
         // Assume the opponent will try to beat our last move.
         return beats(beats(moveHistory[moveHistory.size()-1].m_me));
      }

      // If we lost the last two games
      if ((beats(moveHistory[moveHistory.size()-1].m_me) == moveHistory[moveHistory.size()-1].m_you)
       && (beats(moveHistory[moveHistory.size()-2].m_me) == moveHistory[moveHistory.size()-2].m_you))
      {
         // Assume the opponent will copy our last move.
         return beats(moveHistory[moveHistory.size()-1].m_me);
      }

      // If we lost the last game
      if (beats(moveHistory[moveHistory.size()-1].m_me) == moveHistory[moveHistory.size()-1].m_you)
      {
         // Assume the opponent will try to beat our last move.
         return beats(beats(moveHistory[moveHistory.size()-1].m_me));
      }

      // If we won the last two game
      if ((moveHistory[moveHistory.size()-1].m_me == beats(moveHistory[moveHistory.size()-1].m_you))
       && (moveHistory[moveHistory.size()-2].m_me == beats(moveHistory[moveHistory.size()-2].m_you)))
      {
         // Just keep playing the same
         return moveHistory[moveHistory.size()-1].m_me;
      }

      // If we won the last game
      if (moveHistory[moveHistory.size()-1].m_me == beats(moveHistory[moveHistory.size()-1].m_you))
      {
         // Assume the opponent will copy our last move.
         return beats(moveHistory[moveHistory.size()-1].m_me);
      }

      // Otherwise play whatever beats the opponents move some time ago.
      switch (rand()%1)
      {
         case 0:  return beats(beats(moveHistory[moveHistory.size()-1].m_me));
         default: return beats(moveHistory[moveHistory.size()-1].m_you);
      }
   } // end of int move

private:
   int m_first;

}; // end of PlayerMike

#endif // _PLAYER_MIKE_H_

