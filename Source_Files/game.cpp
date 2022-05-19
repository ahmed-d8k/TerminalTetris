
#include "..\Header_Files\game.h"
#include "..\Header_Files\game_map.h"
#include "..\Header_Files\player.h"
#include "..\Header_Files\wall.h"

#include <iostream>

        //Game();
        //~Game();
        //void start();
        //void engine();

Game::Game():
    m(Game_Map()),
    p(Player()),
    w(Wall()),
    game_clock(0),
    tick_interval(100),
    running(true)
    {}

Game::~Game(){} //TODO

//Getter
Game_Map& Game::get_map(){return m; }

bool Game::is_running(){return running; }

void Game::inc_game_clock(){
    if(game_clock<10000){
        game_clock++;
    }
    else{
        game_clock = 101; //Very slight continuity error possibly
    }
}

void Game::engine(){
    if(game_clock == 0){m.update_map(); } //Boundary Case

    inc_game_clock();
    if((game_clock % tick_interval) == 0){
        p.fall();

        m.update_map();
    }
    
}



