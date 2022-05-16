
#include "..\Header_Files\p_square.h"
#include "..\Header_Files\p_block.h"
#include "..\Header_Files\block_unit.h"
#include "..\Header_Files\screen.h"

/**
        P_Block(int x, char c);
        virtual ~P_Block() =0;
        virtual void rotate() =0;
        virtual void shift_left() =0;
        virtual void shift_right() =0;
        **/
        //int size, pc_countdown, max_pc_countdown;
        //bool collish, place_collish;
        //char body;
    
P_Square::P_Square(): 
    P_Block::P_Block(4, '@')
{
    psq_vec.push_back(new Block_Unit(Screen::SCREEN_WIDTH/2, 0, body));
    psq_vec.push_back(new Block_Unit(Screen::SCREEN_WIDTH/2 - 1, 0, body));
    psq_vec.push_back(new Block_Unit(Screen::SCREEN_WIDTH/2, 1, body));
    psq_vec.push_back(new Block_Unit(Screen::SCREEN_WIDTH/2 - 1, 1, body));
}

//Not Implemented Yet
P_Square::~P_Square(){}
void P_Square::rotate(){}
void P_Square::shift_left(){}
void P_Square::shift_right(){}




    