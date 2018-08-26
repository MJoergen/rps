#ifndef _PLAYER_ALTERNATE_H_
#define _PLAYER_ALTERNATE_H_

#include <string>
#include "player.h"

// This is another very stupid player: It always
// plays the same two moves over and over!

class PlayerAlternate : public Player
{
public:
   PlayerAlternate(const std::string& name) :
      Player(name),
      m_first(rand()%3),
      m_second(beats(m_first))
   {}

   int move(const std::vector<Move>& moveHistory)
   {
      int play = m_first;
      m_first = m_second;
      m_second = play;
      return play;
   } // end of int move

private:
   int m_first;
   int m_second;

}; // end of PlayerAlternate

#endif // _PLAYER_ALTERNATE_H_

