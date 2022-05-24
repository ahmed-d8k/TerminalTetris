#include <iostream>
#include <list>
#include <chrono>
#include <thread>

#include "..\Header_Files\render.h"
#include "..\Header_Files\game.h"




//Todo List
    //Basic Rendering DONE
    //Create Boundary Object DONE
    //Create Map DONE
    //Create Player Block
        //Square DONE
        //L Right
        //L Left
        //Z Right
        //Z Left
        //T
        //Line
    //Bottom wall needs to be recognized as a place collision DONE
    //Collision DONE
    //Player Control DONE
    //Tetris row deletion DONE
    //Tetris defeat condition
        //If blocks get to a certain height end game

//Issues
    //Possible problem of some objects having pointers to entitys that were deleted by another object
    //Row completing dropping results in the player also dropping, this should not happen
    //Squares can "Rotate". prevent this
int main(){
    Game g;
    while(g.is_running()){

        //Game Logic
        g.engine();

        //Render
        //Render::refresh_screen(g.get_map());
        //Render::refresh_screen(g.get_lmap());
        Render::refresh_screen(g.get_map(), g.get_lmap()); //Remember previous functions dont have render time logic
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        

    }

    std::cout << "Program Finished Succesfully\n";
}