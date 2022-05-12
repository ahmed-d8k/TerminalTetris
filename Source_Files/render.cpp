#include <iostream>
#include <vector>


#include "..\Header_Files\entity.h"
#include "..\Header_Files\render.h"
#include "..\Header_Files\screen.h"

void Render::clear_screen(){
    system("cls");
}

void Render::draw_unit(Entity *e){
    std::cout << e->get_body();
}

void Render::draw_screen(Entity *e){}

void Render::render_engine(Wall &w){
    bool e_drawn;
    for(int i = 0; i < Screen::SCREEN_HEIGHT; i++){
        for(int j = 0; j< Screen::SCREEN_WIDTH; j++){
            e_drawn = false;

            //Wall
            for(Entity *e : w.get_wall()){
                if((e->get_y() == i) && (e->get_x() == j)){
                    draw_unit(e);
                     e_drawn = true;
                }
            }





            if(e_drawn == false){std::cout << "~"; }
        }
        std::cout << "\n";
    }
}

void Render::refresh_screen(Wall &w){
    Render::clear_screen();
    Render::render_engine(w);

}



