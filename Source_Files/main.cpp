#include <iostream>
#include <list>

#include "..\Header_Files\render.h"
#include "..\Header_Files\entity.h"
#include "..\Header_Files\wall_unit.h" //remove
#include  "..\Header_Files\wall.h"
#include "..\Header_Files\game_map.h"



//Todo List
    //Basic Rendering DONE
    //Create Boundary Object DONE
    //Create Map DONE
    //Create Player Block
        //Square
        //L Right
        //L Left
        //Z Right
        //Z Left
        //T
        //Line
    //Player Control
    //Collision
    //Check if row full, rmove and drop structure
int main(){
    bool running = true;
    Game_Map m;
    while(running){

        //Game Logic

        //Render
        m.update_map();
        Render::refresh_screen(m);
        



        running = false;
    }

    std::cout << "Program Finish Succesfully\n";
}