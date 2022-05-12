#ifndef WALL_H
#define WALL_H

#include "wall_unit.h"
#include "vector"


class Wall{
    friend class Wall_Unit;
    protected:
        int unit_count;
        std::vector<Wall_Unit*> wall_vec;
    public:
        Wall();
        ~Wall();
        std::vector<Wall_Unit*>& get_wall();
        int get_units();

};

#endif