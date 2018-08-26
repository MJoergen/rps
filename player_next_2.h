#ifndef _PLAYER_NEXT_2_H_
#define _PLAYER_NEXT_2_H_

#include <string>
#include "player.h"

// A slightly smarter player that usually 
// plays the move that beats the opponents previous move.
// However, if it has lost the last three games, it will
// play a random move.

class PlayerNext_2 : public Player
{
public:
   PlayerNext_2(const std::string& name) :
      Player(name)
   {}

   int move(const std::vector<Move>& moveHistory)
   {
      // First move, just choose randomly
      if (moveHistory.size() == 0)
         return rand() % 3;

      // The first few games, just play whatever beats the opponents last move.
      if (moveHistory.size() < 3)
      {
         return beats(moveHistory[moveHistory.size()-1].m_you);
      }
      

      // Figure out if we lost the last three games.
      int allLost = 1;  // Assume we lost
      for (int i=1; i<=3; ++i)
      {
         if (beats(moveHistory[moveHistory.size()-i].m_me) != moveHistory[moveHistory.size()-i].m_you)
         {
            // OK, didn't lose.
            allLost = 0;
            break;
         }
      }

      if (!allLost)
      {
         return beats(moveHistory[moveHistory.size()-1].m_you);
      }

      return rand() % 3;
   } // end of int move

private:

}; // end of PlayerNext_2

#endif // _PLAYER_NEXT_2_H_

