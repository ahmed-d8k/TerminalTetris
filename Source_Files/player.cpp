

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
    collish(false),
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

void Player::get_next_pb(){
    delete pb;
    pb = new P_Square();
}

void Player::movement_engine(Logic_Map &lm){
    place_collish = pb->ground_collision(lm);
    if(!place_collish){place_count = 0; fall(lm); }
    else if(place_collish){place_pb(); }
    

}


