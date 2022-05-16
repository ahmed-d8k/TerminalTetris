

#include "..\Header_Files\player.h"
#include "..\Header_Files\p_square.h"

Player::Player(): pb(new P_Square()){} //Eventually this will randomly select from all player types
Player::~Player(){delete pb; }