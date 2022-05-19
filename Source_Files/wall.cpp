
#include "..\Header_Files\wall.h"
#include "..\Header_Files\wall_unit.h"
#include "..\Header_Files\screen.h"

//Height*2 + width - 2
//Wall ground logic bothers me, check later

Wall::Wall():
    unit_count(Screen::SCREEN_HEIGHT*2 + Screen::SCREEN_WIDTH - 2)
{   
    int x = 0, y = 0;
    for(int i = 0; i < unit_count; i++){
        if((y < (Screen::SCREEN_HEIGHT - 1)) && (x < (Screen::SCREEN_WIDTH - 2))){ //Left Wall
            wall_vec.push_back((new Wall_Unit(x,y, false)));
            y++;
        }
        else if((y == (Screen::SCREEN_HEIGHT - 1)) && (x < (Screen::SCREEN_WIDTH - 1))){ //Bottom Wall
            wall_vec.push_back((new Wall_Unit(x,y,true)));
            x++;
        }
        else{
            wall_vec.push_back((new Wall_Unit(x,y,false))); //Right Wall
            y--;
        }

    }
}

Wall::~Wall(){
    wall_vec.clear();
    wall_vec.shrink_to_fit();
}

//Getter
std::vector<Wall_Unit*>& Wall::get_wall(){
    return wall_vec;
}
int Wall::get_units(){
    return unit_count;
}

