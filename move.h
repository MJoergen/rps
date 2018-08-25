#ifndef _MOVE_H_
#define _MOVE_H_

const int ROCK     = 0;
const int PAPER    = 1;
const int SCISSORS = 2;

int beats(int draw);

// A single move consists of a draw from each player
class Move
{
   public:
      Move(int me, int you) : m_me(me), m_you(you) {}

   public:
      int m_me;
      int m_you;
}; // end of class Move

#endif // _MOVE_H_

