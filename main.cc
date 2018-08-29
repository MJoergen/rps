#include <vector>
#include <stdlib.h>
#include "tournament.h"
#include "player.h"
#include "player_const.h"
#include "player_const_2.h"
#include "player_alternate.h"
#include "player_cycle.h"
#include "player_cycle_2.h"
#include "player_cycle_3.h"
#include "player_copy.h"
#include "player_next.h"
#include "player_next_2.h"
#include "player_anti_next.h"
#include "player_random.h"
#include "player_random_dist.h"
#include "player_mike.h"
#include "player_mike_2.h"
#include "player_mike_3.h"
#include "player_mike_4.h"
#include "player_ask.h"
#include "player_mads.h"
#include "player_delay.h"
#include "player_anti_mike.h"
#include "delay_2.h"

#ifdef DEBUG
const int numGames = 50;
#else
const int numGames = 1000;
#endif

int main()
{
   srand(time(0));

   std::vector<Player *> players;

   players.push_back(new PlayerConst(     "ROCK",       0));
   players.push_back(new PlayerConst(     "PAPER",      1));
   players.push_back(new PlayerConst(     "SCISSORS",   2));
   players.push_back(new PlayerConst_2(   "CONST_2"      ));
   players.push_back(new PlayerAlternate( "ALTERNATE"    ));
   players.push_back(new PlayerCycle(     "CYCLE"        ));
   players.push_back(new PlayerCycle_2(   "CYCLE_2"      ));
   players.push_back(new PlayerCycle_3(   "CYCLE_3"      ));
   players.push_back(new PlayerCopy(      "COPY",       0));
   players.push_back(new PlayerNext(      "NEXT",       0));
   players.push_back(new PlayerNext_2(    "NEXT_2"       ));
   players.push_back(new PlayerAntiNext(  "ANTI_NEXT",  0));
   players.push_back(new PlayerRandomDist("RANDOM_DIST"  ));
   players.push_back(new PlayerRandom(    "RANDOM"       ));
   players.push_back(new PlayerMike(      "MIKE"         ));
   players.push_back(new PlayerAsk(       "ASK"          ));
   players.push_back(new PlayerMike_2(    "MIKE_2"       ));
   players.push_back(new PlayerMike_3(    "MIKE_3"       ));
   players.push_back(new PlayerMike_4(    "MIKE_4"       ));
   players.push_back(new PlayerMads(      "MADS"         ));
   players.push_back(new PlayerDelay(     "DELAY"        ));
   players.push_back(new PlayerAntiMike(  "ANTI_MIKE"    ));
   players.push_back(new PlayerDelay_2 (   "DELAY_2"     ));

   Tournament t(players, numGames);
   
   t.play();

   t.showTable();
   t.show();
} // end of main

