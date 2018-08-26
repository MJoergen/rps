#ifndef _PLAYER_ANTI_NEXT_H_
#define _PLAYER_ANTI_NEXT_H_

#include <string>
#include "player.h"

// This is a very simple player: It always
// expects the opponent to play whatever move that beats
// my previous move, and plays accordingly.
// The first move is selected in the constructor.

class PlayerAntiNext : public Player
{
public:
   PlayerAntiNext(const std::string& name, int first) :
      Player(name),
      m_first(first)
   {}

   int move(const std::vector<Move>& moveHistory)
   {
      if (moveHistory.size() > 0)
         return beats(beats(moveHistory.back().m_me));
      else
         return m_first;
   } // end of int move

private:
   int m_first;

}; // end of PlayerAntiNext

#endif // _PLAYER_ANTI_NEXT_H_

