#include <iostream>


#include "..\Header_Files\entity.h"
#include "..\Header_Files\render.h"
#include "..\Header_Files\screen.h"

/**
 *      void clear_screen();
        void draw_unit(auto u);
        void draw_screen();
        void refresh_screen();
        void render_engine();
 * 
 */

void Render::clear_screen(){
    system("cls");
}

void Render::draw_unit(Entity *e){
    std::cout << e->get_body();
}

void Render::draw_screen(Entity *e){}

void Render::render_engine(Entity *e){
    for(int i = 0; i < Screen::SCREEN_HEIGHT; i++){
        for(int j = 0; j< Screen::SCREEN_WIDTH; j++){
            if((e->get_y() == i) && (e->get_x() == j)){
                draw_unit(e);
            }
            else{
                std::cout << "A";
            }
        }
        std::cout << "\n";
    }
}

void Render::refresh_screen(Entity *e){
    Render::clear_screen();
    Render::render_engine(e);

}



