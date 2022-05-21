#ifndef LOGIC_MAP_H
#define LOGIC_MAP_H

#include <vector>
#include <deque>

#include "screen.h"



class Logic_Map{
    friend class Entity;
    protected:
        char bg;
        std::vector<std::vector<char>> *lmap;
    public:
        Logic_Map();
        ~Logic_Map();

        std::vector<std::vector<char>>* get_lmap();
        void update_lmap();
        void clear_lmap();
        void paint_lmap();


};

#endif