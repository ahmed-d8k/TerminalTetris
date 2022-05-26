#include "..\Header_Files\p_line.h"
#include "..\Header_Files\p_block.h"
#include "..\Header_Files\block_unit.h"
#include "..\Header_Files\screen.h"
    
P_Line::P_Line(): 
    P_Block::P_Block(4, '@')
{
    p_vec.push_back(new Block_Unit(Screen::SCREEN_WIDTH/2, 1, body));
    p_vec.push_back(new Block_Unit(Screen::SCREEN_WIDTH/2 - 1, 1, body));
    p_vec.push_back(new Block_Unit(Screen::SCREEN_WIDTH/2 + 1, 1, body));
    p_vec.push_back(new Block_Unit(Screen::SCREEN_WIDTH/2 + 2, 1, body));
}

P_Line::~P_Line(){}
