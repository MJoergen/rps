#ifndef _PLAYER_CONST_H_
#define _PLAYER_CONST_H_

#include <string>
#include "player.h"

// This is a very stupid player: It always
// plays the same move every time!
//
// The particular move it plays is selected
// in the constructor.

class PlayerConst : public Player
{
public:
   PlayerConst(const std::string& name, int play) :
      Player(name),
      m_play(play)
   {}

   int move(const std::vector<Move>& moveHistory)
   {
      return m_play;
   } // end of int move

private:
   int m_play;

}; // end of PlayerConst

#endif // _PLAYER_CONST_H_

