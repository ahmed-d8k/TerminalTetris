#ifndef GAME_H
#define GAME_H

#include "game_map.h"
#include "player.h"
#include "Wall.h"
#include "logic_map.h"



class Game{
    protected:
        Game_Map m;
        Logic_Map lm;
        Player p;
        Wall w;
        int game_clock, tick_interval, score;
        bool running, paused;
    public:
        Game();
        ~Game();
        Game_Map& get_map();
        Logic_Map& get_lmap();

        int get_score();

        bool is_running();
        bool is_paused();

        void end_game();
        void inc_game_clock();
        void start();
        void engine();
        void defeat();


};

#endif