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
        virtual int temp() =0;
};

class Polygon{
    protected:
        int l, h;
    public:
        Polygon(): l(5), h(5) {}
        Polygon(int x, int y): l(x), h(y) {}
        void change_val(int x, int y){l = x; h=y; }
        virtual int area(){return 0; } //Keyword virtual makes the object use the original types func definition
};

class Rectangle: public Polygon{
    public:
        Rectangle(int x, int y): Polygon(x, y) {}
        int area(){return l*h; }
};

#endif