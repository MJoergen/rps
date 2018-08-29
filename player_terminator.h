#ifndef _PLAYER_TERMINATOR_H_
#define _PLAYER_TERMINATOR_H_

#include <string>
#include <iomanip>
#include <stdlib.h>
#include "player.h"
#include "player_delay_2.h"
#include "player_next.h"
#include "player_copy.h"
#include "player_cycle_3.h"

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
      PlayerDelay   delay("terminator");
      PlayerDelay_2 delay_2("terminator");
      PlayerNext    next("terminator", 0);
      PlayerCopy    copy("terminator", 0);
      PlayerCycle_3 cycle_3("terminator");

      // Loop over all the moves played so far, and count the number of times
      // the move played by the opponent matches that predicted by our local
      // instantiation of DELAY.
      std::vector<Move> invertedMoveHistory;
      invertedMoveHistory.reserve(moveHistory.size());   // Optimization
      unsigned int correctDelay   = 0;
      unsigned int correctDelay_2 = 0;
      unsigned int correctNext    = 0;
      unsigned int correctCopy    = 0;
      unsigned int correctCycle_3 = 0;
      for (size_t i=0; i<moveHistory.size(); ++i)
      {
         const int predictedMoveDelay   = delay.move(invertedMoveHistory);
         const int predictedMoveDelay_2 = delay_2.move(invertedMoveHistory);
         const int predictedMoveNext    = next.move(invertedMoveHistory);
         const int predictedMoveCopy    = copy.move(invertedMoveHistory);
         const int predictedMoveCycle_3 = cycle_3.move(invertedMoveHistory);
         const Move& playedMove = moveHistory[i];

         if (predictedMoveDelay == playedMove.m_you)
         {
            correctDelay += 1;
         }
         if (predictedMoveDelay_2 == playedMove.m_you)
         {
            correctDelay_2 += 1;
         }
         if (predictedMoveNext == playedMove.m_you)
         {
            correctNext += 1;
         }
         if (predictedMoveCopy == playedMove.m_you)
         {
            correctCopy += 1;
         }
         if (predictedMoveCycle_3 == playedMove.m_you)
         {
            correctCycle_3 += 1;
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
      if (correctCycle_3*2 > moveHistory.size())
         return beats(cycle_3.move(invertedMoveHistory));
      else if (correctNext*2 > moveHistory.size())
         return beats(next.move(invertedMoveHistory));
      else if (correctDelay_2*2 > moveHistory.size())
         return beats(delay_2.move(invertedMoveHistory));
      else if (correctDelay*2 > moveHistory.size())
         return beats(delay.move(invertedMoveHistory));
      else if (correctCopy*2 > moveHistory.size())
         return beats(copy.move(invertedMoveHistory));
      else
         return delay.move(moveHistory);

   } // end of int move
}; // end of PlayerTerminator

#endif // _PLAYER_TERMINATOR_H_

