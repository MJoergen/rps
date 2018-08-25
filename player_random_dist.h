#ifndef _PLAYER_RANDOM_DIST_H_
#define _PLAYER_RANDOM_DIST_H_

#include <time.h>
#include "player.h"
#include <iostream>

class PlayerRandomDist : public Player
{
public:
	PlayerRandomDist(const std::string& name) :
		Player(name)
	{
		srand(time(0));
	}

	int move(const std::vector<Move>& moveHistory)
	{
		if (moveHistory.size() == 0) { //The first move
			opponentMoveCounts[0] = 0;
			opponentMoveCounts[1] = 0;
			opponentMoveCounts[2] = 0;
			return rand() % 3;
		}

		++opponentMoveCounts[moveHistory[moveHistory.size() - 1].m_you];

		double randVal = (double)rand()/RAND_MAX;
		if (randVal <= (double)opponentMoveCounts[0] / moveHistory.size()) {
			return PAPER;
		}
		else if(randVal <= ((double)opponentMoveCounts[0] + opponentMoveCounts[1])/moveHistory.size()) {
			return SCISSORS;
		}
		return ROCK;
	} // end of int move

private:
	int opponentMoveCounts[3];
}; // end of PlayerRandom

#endif // _PLAYER_RANDOM_H_

