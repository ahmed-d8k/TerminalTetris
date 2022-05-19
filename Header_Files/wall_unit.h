#ifndef WALL_UNIT_H
#define WALL_UNIT_H

#include "entity.h"

class Wall_Unit: public Entity{
    public:
        Wall_Unit(int x, int y, bool b);
        ~Wall_Unit();
};

#endif