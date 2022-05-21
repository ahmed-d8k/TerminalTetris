#include <iostream>
#include <windows.h>

#include "..\Header_Files\game.h"
#include "..\Header_Files\game_map.h"
#include "..\Header_Files\player.h"
#include "..\Header_Files\wall.h"
#include "..\Header_Files\logic_map.h"
#include "..\Header_Files\entity.h"



Game::Game():
    m(Game_Map()),
    lm(Logic_Map()),
    p(Player()),
    w(Wall()),
    game_clock(0),
    tick_interval(10),
    running(true)
    {}

Game::~Game(){} //TODO

//Getter
Game_Map& Game::get_map(){return m; }
Logic_Map& Game::get_lmap(){return lm; }

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
    if(game_clock == 0){m.update_map(); lm.update_lmap();} //Boundary Case
    

    inc_game_clock();
    if((game_clock % tick_interval) == 0){
        p.movement_engine(lm);
        Entity::check_rows(lm);

        m.update_map();
        lm.update_lmap();
    }
    
}



