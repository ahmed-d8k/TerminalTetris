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
        //std::vector<Block_Unit*> pb_vec;
    public:
        P_Block(int x, char c);
        virtual ~P_Block();
        virtual void rotate() =0;
        virtual void shift_left() =0;
        virtual void shift_right() =0;
        void fall_down ();
        bool ground_collision(Logic_Map &lm);
        bool wall_collision(Logic_Map &lm);

};

#endif