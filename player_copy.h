#ifndef _PLAYER_COPY_H_
#define _PLAYER_COPY_H_

#include <string>
#include "player.h"

// This is a very simple player: It always
// plays the same move as the opponents previous move!
// The first move is selected in the constructor

class PlayerCopy : public Player
{
public:
   PlayerCopy(const std::string& name, int first) :
      Player(name),
      m_first(first)
   {}

   int move(const std::vector<Move>& moveHistory)
   {
      if (moveHistory.size() > 0)
         return moveHistory.back().m_you;
      else
         return m_first;
   } // end of int move

private:
   int m_first;

}; // end of PlayerCopy

#endif // _PLAYER_COPY_H_

