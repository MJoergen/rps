#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include "tournament.h"
#include "match.h"

void Tournament::play(int numGames)
{
   for (int p1=0; p1<m_players.size(); ++p1)
   {
      for (int p2=p1+1; p2<m_players.size(); ++p2)
      {
         Match match(m_players[p1], m_players[p2]);
         int res = match.play(numGames);

         if (res > 0)
            std::cout << "The winner is " << m_players[p1]->name() << " with " << res << " points";
         else if (res < 0)
            std::cout << "The winner is " << m_players[p2]->name() << " with " << -res << " points";
         else
            std::cout << "The match ended in a DRAW!";
         std::cout << std::endl;
         std::cout << std::endl;

         m_scores[p1] += res;
         m_scores[p2] -= res;
      }
   }
} // end of play

void Tournament::show()
{
   std::multimap<int, std::string, std::greater<int> > result;

   for (int p1=0; p1<m_players.size(); ++p1)
   {
      result.insert(std::pair<int, std::string>(m_scores[p1], m_players[p1]->name()));
   }

   for (auto& line : result)
   {
      std::cout << std::setw(10) << line.second << " : " << line.first << std::endl;
   }

   std::cout << std::endl;

} // end of show

