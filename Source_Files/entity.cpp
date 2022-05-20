
#include <algorithm>

#include "..\Header_Files\entity.h"

std::deque<Entity*>Entity::entities;

Entity::Entity(int x, int y, char c, bool g, bool w): x(x), y(y), body(c), ground(g), wall(w) {entities.push_back(this); }
Entity::~Entity(){entities.erase(std::remove(entities.begin(), entities.end(), this), entities.end()); }



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
