#ifndef _PLAYER_CYCLE_H_
#define _PLAYER_CYCLE_H_

#include <string>
#include "player.h"

// This is a very stupid player: It always
// plays the same sequence of moves over and over!

class PlayerCycle : public Player
{
public:
   PlayerCycle(const std::string& name) :
      Player(name),
      m_play(rand()%3)
   {}

   int move(const std::vector<Move>& moveHistory)
   {
      m_play = beats(m_play);
      return m_play;
   } // end of int move

private:
   int m_play;

}; // end of PlayerCycle

#endif // _PLAYER_CYCLE_H_

