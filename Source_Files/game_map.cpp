#include <vector>

#include "..\Header_Files\game_map.h"
#include "..\Header_Files\screen.h"
#include "..\Header_Files\entity.h"

Game_Map::Game_Map():
    bg('~')
{
    map = new std::vector<std::vector<char>> (Screen::SCREEN_HEIGHT, std::vector<char>(Screen::SCREEN_WIDTH, bg));
}

Game_Map::~Game_Map(){
    delete map;
}

//Getters
std::vector<std::vector<char>>* Game_Map::get_map(){
    return map;
}


//Don't like this implementation atm
void Game_Map::clear_map(){
    delete map;
    map = new std::vector<std::vector<char>> (Screen::SCREEN_HEIGHT, std::vector<char>(Screen::SCREEN_WIDTH, bg));


    //for (std::vector<char> row : *map){
    //    row.assign(Screen::SCREEN_WIDTH, bg);
    //}
}

void Game_Map::update_map(){
    clear_map();
    for(Entity *e: Entity::entities){
        map->at(e->get_y()).at(e->get_x()) = e->get_body();
    }
}

