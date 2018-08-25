#ifndef _PLAYER_RANDOM_H_
#define _PLAYER_RANDOM_H_

#include <string>
#include <stdlib.h>
#include <time.h>
#include "player.h"

// This is the "optimal" player: It always
// plays a completely random move.

class PlayerRandom : public Player
{
public:
   PlayerRandom(const std::string& name) :
      Player(name)
   {}

   int move(const std::vector<Move>& moveHistory)
   {
      return rand() % 3;
   } // end of int move

private:

}; // end of PlayerRandom

#endif // _PLAYER_RANDOM_H_

