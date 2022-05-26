#ifndef RENDER_H
#define RENDER_H

#include "entity.h"
#include "screen.h"
#include "wall.h"
#include "game_map.h"
#include "logic_map.h"
#include "game.h"

class Render {
    friend class Screen;
    friend class Game_Map;
    public:
        const static int render_cycle = 1;
        static int iter_since_last_render;
        static bool paused;
        static void inc_render_clock();
        static void clear_screen();
        static void draw_unit(Entity *e);
        static void refresh_screen(Game &g);
        static void refresh_screen(Game_Map &m);
        static void render_engine(Game_Map &m);
        static void refresh_screen(Logic_Map &m);
        static void render_engine(Logic_Map &m);
        static void refresh_screen(Game_Map &m, Logic_Map &lm);
        static void render_engine(Game_Map &m, Logic_Map &lm);
        static void draw_screen(Entity *e);
};

#endif