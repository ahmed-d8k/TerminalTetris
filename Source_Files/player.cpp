#include <windows.h>
#include <conio.h>

#include "..\Header_Files\player.h"
#include "..\Header_Files\p_square.h"
#include "..\Header_Files\logic_map.h"
#include "..\Header_Files\entity.h" //remopve prob

Player::Player(): 
    pb(new P_Square()),
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
    pb = new P_Square();
}

char Player::handle_kb(){
    char in1, in2;
    in1 = getch();
    if(_kbhit()){in2 = getch(); }
    FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
    if(in1 == -32){return in2; }
    else{return in1; }
}

//When block touches wall it can no longer move, wrong
//Blocks cant fall into the ground but it can shift left and right into it
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
            break;
        case 'p': //Pause Game
            break;
    }
    
    if(!place_collish){place_count = 0; fall(lm); }
    else if(place_collish){place_pb(); }
}



