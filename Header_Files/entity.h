#ifndef ENTITY_H
#define ENTITY_H

#include <deque>
#include <vector>

#include "logic_map.h"

class Entity{
    protected:
        int x, y;
        char body;
        bool ground, wall;
        
    public:
        static std::deque<Entity*> entities;
        Entity(int x, int y, char c, bool g, bool w);
        virtual ~Entity(); //=0?
        int get_x();
        int get_y();
        char get_body();
        bool is_ground();
        bool is_wall();
        void set_x(int new_x);
        void set_y(int new_y);
        void set_ground_true();
        bool static row_full(std::vector<char> row);
        void static clear_row(int row_num);
        void static drop_all(int rows_removed);
        int static check_rows(Logic_Map &lm);//This function really does not belong here
};

#endif