#include <vector>

#include "..\Header_Files\logic_map.h"
#include "..\Header_Files\screen.h"
#include "..\Header_Files\entity.h"

/*In theory could make an abstract map class but not doing that right now*/

Logic_Map::Logic_Map():
    bg(' ')
{
    lmap = new std::vector<std::vector<char>> (Screen::SCREEN_HEIGHT, std::vector<char>(Screen::SCREEN_WIDTH, bg));
}

Logic_Map::~Logic_Map(){
    delete lmap;
}

/*Getters*/
std::vector<std::vector<char>>* Logic_Map::get_lmap(){
    return lmap;
}


/*Don't like this implementation atm*/
void Logic_Map::clear_lmap(){
    delete lmap;
    lmap = new std::vector<std::vector<char>> (Screen::SCREEN_HEIGHT, std::vector<char>(Screen::SCREEN_WIDTH, bg));
}

void Logic_Map::update_lmap(){
    clear_lmap();
    for(Entity *e: Entity::entities){
        if(e->is_ground() == true && e->is_wall() == true){
            lmap->at(e->get_y()).at(e->get_x()) = 'G';
        }
        else if(e->is_ground() == false && e->is_wall() == true){
            lmap->at(e->get_y()).at(e->get_x()) = 'w';
        }
        else if(e->is_ground() == true && e->is_wall() == false){
            lmap->at(e->get_y()).at(e->get_x()) = 'g';
        }
        else{
            lmap->at(e->get_y()).at(e->get_x()) = 'e';
        }
    }
}

