#ifndef PLAYER_H
#define PLAYER_H

#include "p_block.h"

class Player{
    protected:
        P_Block *pb;
        int fall_cycle, cycles_since_last_fall;
    public:
        Player();
        ~Player();

        void fall();
};

#endif