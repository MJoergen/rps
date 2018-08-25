#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <vector>
#include <string>
#include "move.h"

// This is the base class
class Player
{
public:
   Player(const std::string& name) :
      m_name(name)
      {}

   virtual ~Player() {}

   virtual int move(const std::vector<Move>& moveHistory) = 0;

   std::string name() const {return m_name;}

private:
   std::string m_name;

}; // end of Player

#endif // _PLAYER_H_

