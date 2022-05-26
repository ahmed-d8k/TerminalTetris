#ifndef P_BLOCK_H
#define P_BLOCK_H

#include <vector>

#include "block_unit.h"
#include "logic_map.h"

class P_Block{
    friend class Block_unit;
    protected:
        int size, pc_countdown, max_pc_countdown;
        char body;
        std::vector<Block_Unit*> p_vec;
    public:
        P_Block(int x, char c);
        virtual ~P_Block();
        void rotate();
        void shift_left();
        void shift_right();
        void fall_down ();
        bool ground_collision(Logic_Map &lm);
        bool left_collision(Logic_Map &lm);
        bool right_collision(Logic_Map &lm);
        void set_ground();
};

#endif