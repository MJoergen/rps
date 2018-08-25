#ifndef _PLAYER_NEXT_H_
#define _PLAYER_NEXT_H_

#include <string>
#include "player.h"

// This is a very simple player: It always
// plays the move that beats the opponents previous move!
// The first move is selected in the constructor

class PlayerNext : public Player
{
public:
   PlayerNext(const std::string& name, int first) :
      Player(name),
      m_first(first)
   {}

   int move(const std::vector<Move>& moveHistory)
   {
      if (moveHistory.size() > 0)
         return beats(moveHistory[moveHistory.size()-1].m_you);
      else
         return m_first;
   } // end of int move

private:
   int m_first;

}; // end of PlayerNext

#endif // _PLAYER_NEXT_H_

