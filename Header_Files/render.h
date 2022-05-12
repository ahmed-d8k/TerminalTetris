#ifndef RENDER_H
#define RENDER_H

#include "entity.h"
#include "screen.h"
#include "wall.h"



class Render {
    friend class Screen;
    public:
        static void clear_screen();
        static void draw_unit(Entity *e);
        static void refresh_screen(Wall &w);
        static void render_engine(Wall &w);

        static void draw_screen(Entity *e);
};

#endif