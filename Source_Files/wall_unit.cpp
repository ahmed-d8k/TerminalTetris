
#include "..\Header_Files\entity.h"
#include "..\Header_Files\wall_unit.h"

Wall_Unit::Wall_Unit(int x, int y, bool b): Entity::Entity(x,y,'#', b, true) {}
Wall_Unit::~Wall_Unit(){}