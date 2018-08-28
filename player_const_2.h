#ifndef _PLAYER_CONST_2_H_
#define _PLAYER_CONST_2_H_

#include <string>
#include "player.h"

// This is a very stupid player: It always
// plays the same move almost every time. It
// occasionally changes its mind :-)

class PlayerConst_2 : public Player
{
public:
   PlayerConst_2(const std::string& name) :
      Player(name),
      m_play(rand()%3)
   {}

   int move(const std::vector<Move>& moveHistory)
   {
      // Every ten moves or so, it will change strategy.
      if ((rand()%20) == 0)
      {
         m_play = rand() % 3;
      }
      return m_play;
   } // end of int move

private:
   int m_play;

}; // end of PlayerConst_2

#endif // _PLAYER_CONST_2_H_

