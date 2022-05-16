#ifndef P_SQUARE_H
#define P_SQUARE_H

#include "p_block.h"

class P_Square: public P_Block{
    protected:
        std::vector<Block_Unit*> psq_vec;
    public:
        P_Square();
        ~P_Square();
        void rotate();
        void shift_left();
        void shift_right();

};

#endif