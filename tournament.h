#ifndef _TOURNAMENT_H_
#define _TOURNAMENT_H_

#include <vector>
#include "player.h"

class Tournament
{
public:
   Tournament(const std::vector<Player *> & players) : 
      m_players(players)
   {
      m_scores.resize(m_players.size());
   }

   void play(int numGames);

   void show();

private:
   std::vector<Player *> m_players;
   std::vector<int> m_scores;
};

#endif // _TOURNAMENT_H_

