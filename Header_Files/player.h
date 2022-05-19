#ifndef PLAYER_H
#define PLAYER_H

#include "p_block.h"
#include "logic_map.h"

class Player{
    protected:
        P_Block *pb;
        int fall_cycle, cycles_since_last_fall;
        bool collish, place_collish;
    public:
        Player();
        ~Player();
        void fall(Logic_Map &lm); //Temp argument
        void movement_engine(Logic_Map &lm);
};

#endif