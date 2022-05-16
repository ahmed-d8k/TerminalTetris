#ifndef PLAYER_H
#define PLAYER_H

#include "p_block.h"

class Player{
    protected:
        P_Block *pb;
    public:
        Player();
        ~Player();
};

#endif