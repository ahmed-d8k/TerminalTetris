#ifndef ENTITY_H
#define ENTITY_H

#include <deque>

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
        //virtual int temp() =0;
};

#endif