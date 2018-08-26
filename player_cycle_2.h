#ifndef _PLAYER_CYCLE_2_H_
#define _PLAYER_CYCLE_2_H_

#include <string>
#include "player.h"

// This is a slightly less stupid player: It either
// cycles up or down.
// It randomly changes strategy, every now and then.

class PlayerCycle_2 : public Player
{
public:
   PlayerCycle_2(const std::string& name) :
      Player(name),
      m_play(rand()%3),
      m_up(rand()%2)
   {}

   int move(const std::vector<Move>& moveHistory)
   {
      if ((rand() % 10) == 0)
         m_up = 1 - m_up;

      if (m_up)
         m_play = beats(m_play);
      else
         m_play = beats(beats(m_play));
      return m_play;
   } // end of int move

private:
   int m_play;
   int m_up;

}; // end of PlayerCycle_2

#endif // _PLAYER_CYCLE_2_H_

