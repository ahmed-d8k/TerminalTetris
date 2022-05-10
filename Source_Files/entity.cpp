


#include "entity.h"

Entity::Entity(int x, int y, char c): x(x), y(y), b(c) {}
Entity::~Entity(){}



//Getter
int Entity::get_x(){return x; }
int Entity::get_y(){return y; }
char Entity::get_body(){return b; }

//Setter
void Entity::set_x(int new_x){x = new_x; }
void Entity::set_y(int new_y){y = new_y; }
