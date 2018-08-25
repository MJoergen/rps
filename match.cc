#include <iostream>
#include <string>
#include "assert.h"
#include "match.h"

const std::string names[3] = {"Rock", "Paper", "Scissors"};

int Match::play(int numGames)
{
   std::cout << "Playing match between " << m_p1->name() << " and "
      << m_p2->name() << std::endl;

   // The two variables below contain the same information, but in two different orders.
   std::vector<Move> moveHistory1;  // History of moves so far, seen from p1's perspective.
   std::vector<Move> moveHistory2;  // History of moves so far, seen from p2's perspective.

   int sum = 0;
   for (int g=0; g<numGames; ++g)
   {
      unsigned int draw1 = m_p1->move(moveHistory1);
      unsigned int draw2 = m_p2->move(moveHistory2);

      assert (draw1 < 3);
      assert (draw2 < 3);

      int res = 0;
      switch ((draw1-draw2+3) % 3)
      {
         case 0 : break;    // draw
         case 1 : res = 1;  // P1 wins
                  break;
         case 2 : res = -1; // P1 loses
                  break;
      }

      std::cout << "Game " << g << ": " << names[draw1] << " v " << names[draw2] << " : " << res << std::endl; 

      moveHistory1.push_back(Move(draw1, draw2));
      moveHistory2.push_back(Move(draw2, draw1));

      sum += res;
   } // end of for

   return sum;
} // end of play

