#ifndef PLAYER_H
#define PLAYER_H

#include "p_block.h"
#include "logic_map.h"

class Player{
    protected:
        P_Block *pb;
        int fall_cycle, cycles_since_last_fall, place_count, place_max;
        bool left_collish, right_collish, place_collish;
    public:
        Player();
        ~Player();
        void fall(Logic_Map &lm); //Temp argument
        void player_right();
        void player_left();
        void player_fall();
        void place_pb();
        void movement_engine(Logic_Map &lm);
        void get_next_pb();
        char handle_kb();
};

#endif