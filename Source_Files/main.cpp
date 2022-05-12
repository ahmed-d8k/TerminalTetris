#include <iostream>

#include "..\Header_Files\render.h"
#include "..\Header_Files\entity.h"
#include "..\Header_Files\wall_unit.h" //remove
#include  "..\Header_Files\wall.h"



//Todo List
    //Basic Rendering DONE
    //Create Boundary Object
int main(){
    bool running = true;
    while(running){

        //Game Logic

        //Render
        Wall w;
        Render::refresh_screen(w);
        



        //running = false;
    }

    std::cout << "Program Finish Succesfully\n";
}