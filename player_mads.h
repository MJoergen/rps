//
// Created by mads on 8/27/18.
//

#ifndef RPS_PLAYER_MADS_H
#define RPS_PLAYER_MADS_H

#endif //RPS_PLAYER_MADS_H

#include "player.h"
#include <random>

class PlayerMads : public Player
{
private:
    float calcAvg(std::vector<Move>& moveHistory)
    {
        float sum(0.0);

        for (int i = 0 ; i < moveHistory.size() ; ++i) {
            sum += moveHistory[i].m_you;
        }

        return sum/((float) moveHistory.size());
    }
public:
    PlayerMads(const std::string& name) :
        Player(name)
    {}

    int move (std::vector<Move>& moveHistory)
    {
        float avg = calcAvg(moveHistory);

        std::default_random_engine generator;
        std::normal_distribution<float> distribution(avg, 0.5);

        float rand_result = distribution(generator);

        if (rand_result<= 0.0)
            return ROCK;
        else if (rand_result <= 1.0)
            return PAPER;
        else
            return SCISSORS;
    }
};