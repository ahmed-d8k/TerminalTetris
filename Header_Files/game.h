#ifndef GAME_H
#define GAME_H

#include "game_map.h"
#include "player.h"
#include "Wall.h"



class Game{
    protected:
        Game_Map m;
        Player p;
        Wall w;
        int game_clock, tick_interval;
        bool running;
    public:
        Game();
        ~Game();
        Game_Map& get_map();
        bool is_running();
        void inc_game_clock();
        void start();
        void engine();


};

#endif