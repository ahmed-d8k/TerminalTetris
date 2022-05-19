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

//New implementation for this later. HXW Array that contains all the pieces and their position. Update the HXW Array and then paint this
void Render::render_engine(Game_Map &m){
    std::vector<std::vector<char>> *map = m.get_map();
    for (std::vector<char> row : *map){
        for(char c: row){
            std::cout << c;
        }
        std::cout << "\n";
    }
}

void Render::refresh_screen(Game_Map &m){
    Render::clear_screen();
    Render::render_engine(m);

}

void Render::render_engine(Logic_Map &m){
    std::vector<std::vector<char>> *map = m.get_lmap();
    for (std::vector<char> row : *map){
        for(char c: row){
            std::cout << c;
        }
        std::cout << "\n";
    }
}

void Render::refresh_screen(Logic_Map &m){
    Render::clear_screen();
    Render::render_engine(m);

}

void Render::render_engine(Game_Map &m, Logic_Map &lm){
    std::vector<std::vector<char>> *map = m.get_map();
    std::vector<std::vector<char>> *lmap = lm.get_lmap();

    std::vector<std::vector<char>>::const_iterator m_row_it = map->begin();
    std::vector<std::vector<char>>::const_iterator lm_row_it = lmap->begin();
    for (; m_row_it != map->end() && lm_row_it != lmap->end(); m_row_it++, lm_row_it++){
        std::vector<char>::const_iterator m_col_it = m_row_it->begin();
        std::vector<char>::const_iterator lm_col_it = lm_row_it->begin();
        for(; m_col_it != m_row_it->end(); m_col_it++){
            std::cout << *m_col_it;
        }
        std::cout << " ";
        for(; lm_col_it != lm_row_it->end(); lm_col_it++){
            std::cout << *lm_col_it;
        }
        std::cout << "\n";
    }
}

void Render::refresh_screen(Game_Map &m, Logic_Map &lm){
    Render::clear_screen();
    Render::render_engine(m, lm);

}



