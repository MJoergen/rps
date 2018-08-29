#ifndef _PLAYER_TERMINATOR_H_
#define _PLAYER_TERMINATOR_H_

#include <string>
#include <iomanip>
#include <stdlib.h>
#include "player.h"

// This bot will attempt to "recognize" if the opponent is DELAY, and if so will 
// play a strategy specifically to beat DELAY. If the opponent is not DELAY,
// then this bot will just copy the strategy from DELAY.
// This bot should therefore fare better than DELAY in the tournament.

class PlayerTerminator : public Player
{
public:
   PlayerTerminator(const std::string& name) :
      Player(name)
   {}

   int move(const std::vector<Move>& moveHistory)
   {
      PlayerDelay delay("terminator");
      PlayerMike_4 mike_4("terminator");

      // Loop over all the moves played so far, and count the number of times
      // the move played by the opponent matches that predicted by our local
      // instantiation of DELAY.
      std::vector<Move> invertedMoveHistory;
      invertedMoveHistory.reserve(moveHistory.size());   // Optimization
      unsigned int correctDelay = 0;
      for (size_t i=0; i<moveHistory.size(); ++i)
      {
         const int predictedMoveDelay = delay.move(invertedMoveHistory);
         const Move& playedMove = moveHistory[i];

         if (predictedMoveDelay == playedMove.m_you)
         {
            correctDelay += 1;
         }

         // Update moveHistory with the inverted moves (i.e. as seen by the
         // opponent).
         invertedMoveHistory.push_back(Move(playedMove.m_you, playedMove.m_me));
      }

#ifdef DEBUG
      std::cout << (correctDelay*100.0) / moveHistory.size() << "  " << std::endl;
#endif

      // Determine if the noves played by our opponent matches that of DELAY.
      // If so, play whatever beats DELAY. Otherwise, just copy DELAY's strategy.
      if (correctDelay*2 > moveHistory.size())
         return beats(delay.move(invertedMoveHistory));
      else
         return delay.move(moveHistory);

   } // end of int move
}; // end of PlayerTerminator

#endif // _PLAYER_TERMINATOR_H_

