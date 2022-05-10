#ifndef ENTITY_H
#define ENTITY_H

class Entity{
    protected:
        int x, y;
        char b;
    public:
        Entity(int x, int y, char c);
        ~Entity();
        int get_x();
        int get_y();
        char get_body();
        void set_x(int new_x);
        void set_y(int new_y);
        //virtual int temp() =0;
};

#endif