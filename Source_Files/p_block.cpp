

#include "..\Header_Files\p_block.h"
#include "..\Header_Files\block_unit.h"
P_Block::P_Block(int x, char c):
    size(x),
    pc_countdown(0),
    max_pc_countdown(5),
    collish(false),
    place_collish(false),
    body(c)
{

}

P_Block::~P_Block(){}

void P_Block::fall_down(){
    for(Block_Unit *b: p_vec){
        b->set_y(b->get_y() + 1);
    }
}