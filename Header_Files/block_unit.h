#ifndef BLOCK_UNIT_H
#define BLOCK_UNIT_H


#include "entity.h"

class Block_Unit: public Entity{
    public:
        Block_Unit(int x, int y, char c);
        ~Block_Unit();
};

#endif