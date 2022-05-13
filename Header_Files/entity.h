#ifndef ENTITY_H
#define ENTITY_H

#include <deque>

class Entity{
    protected:
        int x, y;
        char body;
        
    public:
        static std::deque<Entity*> entities;
        Entity(int x, int y, char c);
        virtual ~Entity(); //=0?
        int get_x();
        int get_y();
        char get_body();
        void set_x(int new_x);
        void set_y(int new_y);
        //virtual int temp() =0;
};

#endif