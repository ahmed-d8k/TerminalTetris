#include <algorithm>
#include <deque>
#include <vector>

#include "..\Header_Files\entity.h"
#include "..\Header_Files\logic_map.h"

std::deque<Entity*>Entity::entities;

Entity::Entity(int x, int y, char c, bool g, bool w): x(x), y(y), body(c), ground(g), wall(w) {entities.push_back(this); }
Entity::~Entity(){
    entities.erase(std::remove(entities.begin(), entities.end(), this), entities.end()); 
    }

//Getter
int Entity::get_x(){return x; }
int Entity::get_y(){return y; }
char Entity::get_body(){return body; }
bool Entity::is_ground(){return ground; }
bool Entity::is_wall(){return wall; }

//Setter
void Entity::set_x(int new_x){x = new_x; }
void Entity::set_y(int new_y){y = new_y; }
void Entity::set_ground_true(){ground = true; }

bool Entity::row_full(std::vector<char> row){
    for(char c: row){
        if(c == 'g' || c == 'w'){continue; }
        else{return false; }
    }
    return true;
}

void Entity::clear_row(int row_num){
    std::deque<Entity*>::const_iterator entity_it = entities.begin();
    for(; entity_it != entities.end(); entity_it++){
        if((*entity_it)->get_y() == row_num && (*entity_it)->is_wall() == false){
            delete *entity_it;
            entity_it--;
        }
    }
}

void Entity::drop_all(int row_num){
    for(Entity *e: entities){
        if(e->get_y() < row_num && e->is_wall() == false && e->is_ground() == true){e->set_y(e->get_y() + 1); }
    }
}

int Entity::check_rows(Logic_Map &lm){
    std::vector<std::vector<char>> *lmap = lm.get_lmap();
    bool full = false;
    int row_num = 0;
    int cleared_rows = 0;
    for(std::vector<char> row: *lmap){
        full = row_full(row);
        if(full){
            clear_row(row_num);
            drop_all(row_num);
            cleared_rows++;
        }
        row_num++;
    }
    return cleared_rows;
}
