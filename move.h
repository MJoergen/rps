#ifndef _MOVE_H_
#define _MOVE_H_

const int ROCK     = 0;
const int PAPER    = 1;
const int SCISSORS = 2;

// A single move consists of a draw from each player
class Move
{
   int me;
   int you;
}; // end of class Move

#endif // _MOVE_H_

