//
// Created by mads on 8/29/18.
//

#ifndef RPS_DELAY_2_H
#define RPS_DELAY_2_H

#include "player.h"
#include "move.h"

class PlayerDelay_2 : public Player
{
public:
    PlayerDelay_2 (const std::string& name) :
        Player(name)
        {}

    int move (const std::vector<Move>& moveHistory){
        if (moveHistory.size() < 3){
            return rand() % 3 ;
        } else {
            return beats(moveHistory[moveHistory.size()-3].m_you);
        }
    }
};


#endif //RPS_DELAY_2_H
