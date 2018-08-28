#ifndef _PLAYER_LUKE_H_
#define _PLAYER_LUKE_H_

#include "player.h"

// This is the "optimal" player: It always
// plays a completely random move.

extern "C"
{
   extern int move_c(const Move *moveHistory, size_t numElems);
}

class PlayerLuke : public Player
{
public:
   PlayerLuke(const std::string& name) :
      Player(name)
   {}

   int move(const std::vector<Move>& moveHistory)
   {
      return move_c(&moveHistory[0], moveHistory.size());
   } // end of int move

private:

}; // end of PlayerLuke

#endif // _PLAYER_LUKE_H_

