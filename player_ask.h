#ifndef _PLAYER_ASK_H_
#define _PLAYER_ASK_H_

#include <time.h>
#include "player_random_dist.h"
#include <iostream>

class PlayerAsk : public PlayerRandomDist
{
private:
	int min(const int a, const int b) {
		return a > b ? b : a;
	}

	std::vector<Move> getLastMoves(const std::vector<Move>& moveHistory, const int num) {
		std::vector<Move> result;
		for (int moveId = min(10, moveHistory.size()) - 1; moveId >= 0; --moveId) {
			result.push_back(moveHistory[moveHistory.size() - 1 - moveId]);
		}
		return result;
	}

	bool looksLikeConst(const std::vector<Move>& moveHistory, int& ourNextMove) {
		int rocks = 0;
		int papers = 0;
		int scissors = 0;
		for (Move move : moveHistory) {
			if (move.m_you == ROCK) {
				++rocks;
			}
			else if (move.m_you == PAPER) {
				++papers;
			}
			else {
				++scissors;
			}
		}
		if ((double)rocks / moveHistory.size() > 0.8) { 
			ourNextMove = PAPER;
			return true;
		} else if ((double)papers / moveHistory.size() > 0.8) {
			ourNextMove = SCISSORS;
			return true;
		} else if ((double)scissors / moveHistory.size() > 0.8) {
			ourNextMove = ROCK;
			return true;
		}

		return false;
	}

	bool looksLikeCopy(const std::vector<Move>& moveHistory, int& ourNextMove) {
		if (moveHistory.size() < 2) {
			return false;
		}

		int copied = 0;
		for (int moveId = 1; moveId < moveHistory.size(); ++moveId) {
			if (moveHistory[moveId].m_you == moveHistory[moveId - 1].m_me) {
				++copied;
			}
		}

		if ((double)copied / (moveHistory.size() - 1) > 0.8) {
			ourNextMove = beats(moveHistory[moveHistory.size() - 1].m_me);
			return true;
		}

		return false;
	}


	bool looksLikeNext(const std::vector<Move>& moveHistory, int& ourNextMove) {
		if (moveHistory.size() < 2) {
			return false;
		}

		int nexted = 0;
		for (int moveId = 1; moveId < moveHistory.size(); ++moveId) {
			if (moveHistory[moveId].m_you == beats(moveHistory[moveId - 1].m_me)) {
				++nexted;
			}
		}

		if ((double)nexted / (moveHistory.size() - 1) > 0.8) {
			ourNextMove = beats(beats(moveHistory[moveHistory.size() - 1].m_me));
			return true;
		}

		return false;
	}

public:
	PlayerAsk(const std::string& name) :
		PlayerRandomDist(name)
	{
		srand(time(0));
	}

	int move(const std::vector<Move>& moveHistory)
	{
		//If the opponents strategy can't be determined. Use the RANDOM_DIST algorithm
		int ourNextMove = PlayerRandomDist::move(moveHistory);

		if (moveHistory.size() == 0) { //The first move
			return rand() % 3;
		}

		//Only look at the 10 last moves to take into account that the opponent can change strategy
		std::vector<Move> lastMoves = getLastMoves(moveHistory, 10); 

		if (looksLikeNext(lastMoves, ourNextMove)) {
			return ourNextMove;
		}

		if (looksLikeCopy(lastMoves, ourNextMove)) {
			return ourNextMove;
		}

		if (looksLikeConst(lastMoves, ourNextMove)) {
			return ourNextMove;
		}

		return ourNextMove;
	} // end of int move

}; // end of PlayerRandom

#endif // _PLAYER_RANDOM_H_

