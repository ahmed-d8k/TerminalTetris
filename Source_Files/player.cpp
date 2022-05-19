

#include "..\Header_Files\player.h"
#include "..\Header_Files\p_square.h"
#include "..\Header_Files\logic_map.h"
#include "..\Header_Files\entity.h" //remopve prob

Player::Player(): 
    pb(new P_Square()),
    fall_cycle(0),
    cycles_since_last_fall(0),
    collish(false),
    place_collish(false)
 {} //Eventually this will randomly select from all player types
Player::~Player(){delete pb; }

void Player::fall(Logic_Map &lm){
    place_collish = pb->ground_collision(lm);
    if(!place_collish){
        if(cycles_since_last_fall == fall_cycle){
            pb->fall_down();
            cycles_since_last_fall = 0;
        }
        else{
            cycles_since_last_fall++;
        }
    }
} 

void Player::movement_engine(Logic_Map &lm){

    fall(lm);

}


