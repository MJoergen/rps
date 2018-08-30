//
// Created by mads on 8/30/18.
//

#ifndef RPS_PLAYER_DELAY_3_H
#define RPS_PLAYER_DELAY_3_H

#include "move.h"
#include "player.h"

#include <random>

class PlayerDelay_3 : public Player {
public:
    PlayerDelay_3(const std::string& name) :
    Player (name)
    {}

    int move (const std::vector<Move>& moveHistory){

    if (moveHistory.size() < 2 ){
            return rand() % 3;
        } else {
            return beats(moveHistory[moveHistory.size()-2].m_you);
        }

    }

};


#endif //RPS_PLAYER_DELAY_3_H
