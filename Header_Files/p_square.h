#ifndef P_SQUARE_H
#define P_SQUARE_H

#include "p_block.h"

class P_Square: public P_Block{
    public:
        P_Square();
        ~P_Square();
        void rotate();
        void shift_left(); //Maybe Remove this
        void shift_right(); //Maybe remove this
        void fall_down();
        

};

#endif