#include <vector>
#include "tournament.h"
#include "player.h"
#include "player_const.h"
#include "player_copy.h"
#include "player_next.h"

const int numGames = 10;

int main()
{
   std::vector<Player *> players;

   players.push_back(new PlayerConst("ROCK",     0));
   players.push_back(new PlayerConst("PAPER",    1));
   players.push_back(new PlayerConst("SCISSORS", 2));
   players.push_back(new PlayerCopy( "COPY",     0));
   players.push_back(new PlayerNext( "NEXT",     0));

   Tournament t(players);
   
   t.play(numGames);

   t.show();
   
} // end of main

