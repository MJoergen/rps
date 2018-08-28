#ifndef _PLAYER_DELAY_H_
#define _PLAYER_DELAY_H_

#include <string>
#include "player.h"

// This is a very simple player: It always
// plays the move that beats the opponents previous move!
// The first move is selected in the constructor

class PlayerDelay : public Player
{
public:
   PlayerDelay(const std::string& name) :
      Player(name)
   {}

   int move(const std::vector<Move>& moveHistory)
   {
      if (moveHistory.size() >= 6)
         return beats(moveHistory[moveHistory.size()-6].m_you);
      else
         return rand() % 3;
   } // end of int move

}; // end of PlayerDelay

#endif // _PLAYER_DELAY_H_

