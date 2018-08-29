#ifndef _PLAYER_MIKE_4_H_
#define _PLAYER_MIKE_4_H_

#include <string>
#include <iomanip>
#include <stdlib.h>
#include "player.h"

// This is another awesome player: It uses
// quantum magical algorithms :-)
//
// The method of this player is to build a predictive model of the opponent.
// The model is based on the assumption that the move the opponent selects
// depends on four values: My last move, my previous move, opponents last move, and
// opponents previous move.
// Each of these four inputs take on one of three different values, so there
// are a total of 3^4 = 81 different possible inputs.
// For each input this player counts the number of times the opponent plays each
// of the three moves. So the table contains a total of 81*3 = 243 rows,
// each containing a counter for this particular sequence of events.
// 
// Example:
// Assume the last two moves were (PAPER, ROCK) and (ROCK, SCISSORS).
// If the opponent happens to be the NEXT player, then part of the table
// will look as follows:
//
//  Opp previous | My previous | Opp last | My last | Opp next | Count
//  -------------+-------------+----------+---------+----------+-------
//      ROCK     |   PAPER     | SCISSORS | ROCK    | ROCK     |    0
//      ROCK     |   PAPER     | SCISSORS | ROCK    | PAPER    |  100
//      ROCK     |   PAPER     | SCISSORS | ROCK    | SCISSORS |    0
//
// The table above shows that with this history, there is a large probability
// that the opponents next move will be PAPER. 
//
// Once the above table is built, it is used to randomly predict the opponents
// next move, and we then choose a move that beats that.

class PlayerMike_4 : public Player
{
public:
   PlayerMike_4(const std::string& name) :
      Player(name),
      m_predict(27*9)
   {}

   int move(const std::vector<Move>& moveHistory)
   {
      if (moveHistory.size() >= 2)
      {
         // Attempt to predict the opponents strategy
         fillPredict(moveHistory);

         int row = moveHistory[moveHistory.size()-2].m_you*3*9 + moveHistory[moveHistory.size()-2].m_me*9 +
            moveHistory.back().m_you*3 + moveHistory.back().m_me;

         int s = select(m_predict[row*3], m_predict[row*3+1], m_predict[row*3+2]);

         return beats(s);
      }

      return rand() % 3;

   } // end of int move

private:
   int select(int val0, int val1, int val2)
   {
#ifdef DEBUG
      std::cout << "vals=" << val0 << ", " << val1 << ", " << val2 << std::endl;
#endif
      int sum = val0+val1+val2;
      if (sum == 0)
         return rand() % 3;

      int r = rand()%sum;
      if (r < val0)
         return 0;
      if (r < val0+val1)
         return 1;
      return 2;
   } // end of select

   void fillPredict(const std::vector<Move>& moveHistory)
   {
      for (int ix=0; ix<27*9; ++ix)
      {
         m_predict[ix] = 0;
      }

      for (size_t i=2; i<moveHistory.size(); ++i)
      {
         int ix = moveHistory[i-2].m_you*9*9 + moveHistory[i-2].m_me*3*9 +
            moveHistory[i-1].m_you*9 + moveHistory[i-1].m_me*3 + moveHistory[i].m_you;
         m_predict[ix] += 1;
      }

#ifdef DEBUG
      for (int row=0; row<9*9; ++row)
      {
         std::cout << m_predict[3*row] << " , " << m_predict[3*row+1] << " , " << m_predict[3*row+2] << std::endl;
      }
#endif
   }

private:
   std::vector<int> m_predict;

}; // end of PlayerMike_4

#endif // _PLAYER_MIKE_4_H_

