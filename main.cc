#include <vector>
#include "tournament.h"
#include "player.h"
#include "player_const.h"
#include "player_copy.h"
#include "player_next.h"
#include "player_random.h"
#include "player_random_dist.h"

const int numGames = 1000;

int main()
{
   std::vector<Player *> players;

   players.push_back(new PlayerConst(     "ROCK",       0));
   players.push_back(new PlayerConst(     "PAPER",      1));
   players.push_back(new PlayerConst(     "SCISSORS",   2));
   players.push_back(new PlayerCopy(      "COPY",       0));
   players.push_back(new PlayerNext(      "NEXT",       0));
   players.push_back(new PlayerRandomDist("RANDOM_DIST"  ));
   players.push_back(new PlayerRandom(    "RANDOM"       ));

   Tournament t(players);
   
   t.play(numGames);

   t.show();

} // end of main

