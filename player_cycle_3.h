#ifndef _PLAYER_CYCLE_3_H_
#define _PLAYER_CYCLE_3_H_

#include <string>
#include "player.h"

// This is a cycle player that occasionally "misses a step".
// This is to confuse the opponent :-)

class PlayerCycle_3 : public Player
{
public:
   PlayerCycle_3(const std::string& name) :
      Player(name),
      m_play(rand()%3)
   {}

   int move(const std::vector<Move>& moveHistory)
   {
      if ((rand() % 6) == 0)
      {
         m_play = beats(beats(m_play)); // Step backwards
      }

      m_play = beats(m_play);
      return m_play;
   } // end of int move

private:
   int m_play;

}; // end of PlayerCycle_3

#endif // _PLAYER_CYCLE_3_H_

