#include <iostream>
#include <windows.h>
#include <bits/stdc++.h>

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
    score(0),
    running(true),
    paused(false),
    lost_game(false)
    {}

Game::~Game(){} //TODO

//Getter
Game_Map& Game::get_map(){return m; }
Logic_Map& Game::get_lmap(){return lm; }
int Game::get_score(){return score; }


bool Game::is_running(){return running; }
bool Game::is_paused(){return paused; }
bool Game::is_lost(){return lost_game; }

void Game::end_game(){running = false; }

void Game::inc_game_clock(){
    if(game_clock<10000){
        game_clock++;
    }
    else{
        game_clock = 101; //Very slight continuity error possibly
    }
}

void Game::check_if_lost(){
    int curr_row = 0;
    int end_row = 2;
    for (std::vector<char> row: *lm.get_lmap()){
        for(char c: row){
            if(c == 'g'){lost_game = true; running = false; }
            if(curr_row == end_row){return; }
        }
        curr_row++;
    }
}

void Game::engine(){
    if(p.get_req_end()){end_game(); return; }

    if(game_clock == 0){m.update_map(); lm.update_lmap();} //Boundary Case

    if(!p.get_req_p()){
        paused = false;
        check_if_lost();
        inc_game_clock();

        p.movement_engine(lm);
        int rows_removed = Entity::check_rows(lm);
        if(rows_removed > 0){score += 98 + pow(4, rows_removed); }
        if(p.get_new_pb()){score += 10; }
        m.update_map();
        lm.update_lmap();

        // if((game_clock % tick_interval) == 0){
        //     p.movement_engine(lm);
        //     score += 100*Entity::check_rows(lm);
        //     m.update_map();
        //     lm.update_lmap();
        // }
    }
    else{
        p.paused_engine();
        paused = true;
    }
    
}



