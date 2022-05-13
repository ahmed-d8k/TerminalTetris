
#include <algorithm>

#include "..\Header_Files\entity.h"

std::deque<Entity*>Entity::entities;

Entity::Entity(int x, int y, char c): x(x), y(y), b(c) {entities.push_back(this); }
Entity::~Entity(){entities.erase(std::remove(entities.begin(), entities.end(), this), entities.end()); }



//Getter
int Entity::get_x(){return x; }
int Entity::get_y(){return y; }
char Entity::get_body(){return b; }

//Setter
void Entity::set_x(int new_x){x = new_x; }
void Entity::set_y(int new_y){y = new_y; }
