#include <iostream>

#include "..\Header_Files\render.h"
#include "..\Header_Files\entity.h"
#include "..\Header_Files\wall_unit.h"



//Todo List
    //Basic Rendering
int main(){
    bool running = true;
    while(running){

        //Game Logic

        //Render
        Wall_Unit w (0,0);
        Render::refresh_screen(&w);
        



        running = false;
    }

    std::cout << "Program Finish Succesfully\n";
}