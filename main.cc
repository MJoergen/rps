#include <iostream>
#include <string>
#include "player.h"
#include "player_const.h"

int playMatch(Player *p1, Player *p2)
{
   std::cout << "Playing match between " << p1->name() << " and "
      << p2->name() << std::endl;

   return 0;
}

int main()
{
   std::vector<Player *> players;
   std::vector<int> scores;

   players.push_back(new PlayerConst("ROCK",     0));
   players.push_back(new PlayerConst("PAPER",    1));
   players.push_back(new PlayerConst("SCISSORS", 2));
   
   scores.resize(players.size());

   for (int p1=0; p1<players.size(); ++p1)
   {
      for (int p2=p1+1; p2<players.size(); ++p2)
      {
         int res = playMatch(players[p1], players[p2]);

         scores[p1] += res;
         scores[p2] -= res;
      }
   }
   
} // end of main

