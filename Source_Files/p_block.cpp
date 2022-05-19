

#include "..\Header_Files\p_block.h"
#include "..\Header_Files\block_unit.h"
#include "..\Header_Files\entity.h"

P_Block::P_Block(int x, char c):
    size(x),
    pc_countdown(0),
    max_pc_countdown(5),
    body(c)
{

}

P_Block::~P_Block(){}

void P_Block::fall_down(){
    for(Block_Unit *b: p_vec){
        b->set_y(b->get_y() + 1);
    }
}

void P_Block::ground_collision(){
    for(Block_Unit *b: p_vec){

    }
}

//Not Implemented
void P_Block::wall_collision(){}