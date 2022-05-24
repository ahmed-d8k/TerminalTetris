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

void P_Block::shift_left(){
    for(Block_Unit *b: p_vec){
        b->set_x(b->get_x() - 1);
    }
}

void P_Block::shift_right(){
    for(Block_Unit *b: p_vec){
        b->set_x(b->get_x() + 1);
    }
}

bool P_Block::ground_collision(Logic_Map &lm){
    std::vector<std::vector<char>> *map = lm.get_lmap();

    char pos_state;
    for(Block_Unit *b: p_vec){
        pos_state = (*map)[b->get_y()+1][b->get_x()];
        if(pos_state == 'G' || pos_state == 'g'){ //Need to give 'g' and 'G' variable name
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

bool P_Block::left_collision(Logic_Map &lm){
    std::vector<std::vector<char>> *map = lm.get_lmap();

    char pos_state;
    for(Block_Unit *b: p_vec){
        pos_state = (*map)[b->get_y()][b->get_x()-1];
        if(pos_state == 'w' || pos_state == 'g'){ //Need to give 'w' variable name
            return true;
        }
    }
    return false;
}

bool P_Block::right_collision(Logic_Map &lm){
    std::vector<std::vector<char>> *map = lm.get_lmap();

    char pos_state;
    for(Block_Unit *b: p_vec){
        pos_state = (*map)[b->get_y()][b->get_x()+1];
        if(pos_state == 'w' || pos_state == 'g'){ //Need to give 'w' variable name
            return true;
        }
    }
    return false;
}

void P_Block::rotate(){
    bool first_block = true;
    int orig_x;
    int orig_y;
    int new_x;
    int new_y;
    for(Block_Unit *bu: p_vec){
        if(first_block){
            first_block = false;
            orig_x = bu->get_x();
            orig_y = bu->get_y();
        }
        else{
            new_x = orig_x - (bu->get_y()-orig_y);
            new_y = orig_y + (bu->get_x()-orig_x);
            if(new_x < 0 || new_y < 0){return; }
        }
    }
    for(Block_Unit *bu: p_vec){
        if(first_block){
            first_block = false;
            orig_x = bu->get_x();
            orig_y = bu->get_y();
        }
        else{
            new_x = orig_x - (bu->get_y()-orig_y);
            new_y = orig_y + (bu->get_x()-orig_x);
            if(new_x < 0 || new_y < 0){return; }
            bu->set_x(new_x);
            bu->set_y(new_y);
        }
    }
}