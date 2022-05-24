#include <windows.h>
#include <conio.h>

#include "..\Header_Files\player.h"
#include "..\Header_Files\p_square.h"
#include "..\Header_Files\p_lr.h"
#include "..\Header_Files\p_ll.h"
#include "..\Header_Files\p_t.h"
#include "..\Header_Files\p_zr.h"
#include "..\Header_Files\p_zl.h"
#include "..\Header_Files\p_line.h"
#include "..\Header_Files\logic_map.h"

#include "..\Header_Files\entity.h" //remopve prob

Player::Player(): 
    pb(new P_LR()),
    fall_cycle(3),
    cycles_since_last_fall(0),
    place_count(0),
    place_max(5),
    left_collish(false),
    right_collish(false),
    place_collish(false)
 {} //Eventually this will randomly select from all player types
Player::~Player(){delete pb; }

void Player::fall(Logic_Map &lm){
    
    if(cycles_since_last_fall == fall_cycle){
        pb->fall_down();
        cycles_since_last_fall = 0;
    }
    else{
        cycles_since_last_fall++;
    }
}

void Player::player_left(){
    pb->shift_left();
}

void Player::player_right(){
    pb->shift_right();
}

void Player::player_fall(){
    pb->fall_down();
}

void Player::player_rotate(){
    pb->rotate();
}

void Player::place_pb(){
    if(place_count!=place_max){
        place_count++;
    }
    else{
        place_count = 0;
        pb->set_ground();
        get_next_pb();
    }
}

//Update this function later to roll between all p_block types
void Player::get_next_pb(){
    delete pb;
    auto roll = []() {return rand() % 7 + 1; };
    switch(roll()){
        case 1:
            pb = new P_Square();
            break;
        case 2:
            pb = new P_LR();
            break;
        case 3:
            pb = new P_LL();
            break;
        case 4:
            pb = new P_T();
            break;
        case 5:
            pb = new P_ZL();
            break;
        case 6:
            pb = new P_ZR();
            break;
        case 7:
            pb = new P_Line();
            break;
    }
    
}

char Player::handle_kb(){
    char in1, in2;
    in1 = getch();
    if(_kbhit()){in2 = getch(); }
    FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
    if(in1 == -32){return in2; }
    else{return in1; }
}

void Player::movement_engine(Logic_Map &lm){
    place_collish = pb->ground_collision(lm);
    left_collish = pb->left_collision(lm);
    right_collish = pb->right_collision(lm);
    char input;
    if(_kbhit()){input = handle_kb(); }
    switch(input){
        case 'q': //Quit Game
            break;
        case 'K': //Player Left
            if(!left_collish){player_left(); }
            break; 
        case 'M': //Player Right
            if(!right_collish){player_right(); }
            break;
        case 'P': //Player Down Faster
            if(!place_collish){player_fall(); }
            break;
        case 'r': //Player Rotate
            if(!place_collish && !left_collish && !right_collish){player_rotate(); }
            break;
        case 'p': //Pause Game
            break;
    }
    
    place_collish = pb->ground_collision(lm);
    if(!place_collish){place_count = 0; fall(lm); }
    else if(place_collish){place_pb(); }
}



