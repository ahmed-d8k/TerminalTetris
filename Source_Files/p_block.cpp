#include <iostream>

#include "..\Header_Files\p_block.h"
#include "..\Header_Files\block_unit.h"
#include "..\Header_Files\entity.h"
#include "..\Header_Files\logic_map.h"

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

bool P_Block::ground_collision(Logic_Map &lm){
    std::vector<std::vector<char>> *map = lm.get_lmap();

    char pos_state;
    for(Block_Unit *b: p_vec){
        pos_state = (*map)[b->get_y()+1][b->get_x()];
        if(pos_state == 'G' || pos_state == 'g'){
            return true;
        }
    }
    return false;
}

void P_Block::set_ground(){
    for(Block_Unit *b: p_vec){
        b->set_ground_true();
    }
}

//Not Implemented
bool P_Block::wall_collision(Logic_Map &lm){}