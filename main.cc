#include <iostream>
#include <string>
#include "assert.h"
#include "match.h"
#include "player.h"
#include "player_const.h"
#include "player_copy.h"

const int numGames = 10;

int main()
{
   std::vector<Player *> players;
   std::vector<int> scores;

   players.push_back(new PlayerConst("ROCK",     0));
//   players.push_back(new PlayerConst("PAPER",    1));
   players.push_back(new PlayerConst("SCISSORS", 2));
   players.push_back(new PlayerCopy("COPY", 0));
   
   scores.resize(players.size());

   for (int p1=0; p1<players.size(); ++p1)
   {
      for (int p2=p1+1; p2<players.size(); ++p2)
      {
         Match match(players[p1], players[p2]);
         int res = match.play(numGames);

         if (res > 0)
            std::cout << "The winner is " << players[p1]->name() << " with " << res << " points";
         else if (res < 0)
            std::cout << "The winner is " << players[p2]->name() << " with " << -res << " points";
         else
            std::cout << "The match ended in a DRAW!";
         std::cout << std::endl;
         std::cout << std::endl;

         scores[p1] += res;
         scores[p2] -= res;
      }
   }
   
} // end of main

