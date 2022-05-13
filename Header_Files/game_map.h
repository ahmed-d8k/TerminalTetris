#ifndef GAME_MAP_H
#define GAME_MAP_H

#include <vector>
#include <deque>

#include "screen.h"
#include "entity.h"



class Game_Map{
    friend class Entity;
    protected:
        char bg;
        std::vector<std::vector<char>> *map;
    public:
        Game_Map();
        ~Game_Map();

        std::vector<std::vector<char>>* get_map();
        void update_map();
        void clear_map();
        void paint_map();


};

#endif