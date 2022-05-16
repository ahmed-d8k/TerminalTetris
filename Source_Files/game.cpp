
#include "..\Header_Files\game.h"
#include "..\Header_Files\game_map.h"
#include "..\Header_Files\player.h"
#include "..\Header_Files\wall.h"

        //Game();
        //~Game();
        //void start();
        //void engine();

Game::Game():
    m(Game_Map()),
    p(Player()),
    w(Wall()),
    game_clock(0),
    running(true)
    {}

Game::~Game(){} //TODO

//Getter
Game_Map& Game::get_map(){return m; }

bool Game::is_running(){return running; }

void Game::engine(){
    m.update_map();
}



