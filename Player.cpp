#include "Character.h"
#include "Player.h"

using namespace std;
// functions related to the child class Player

int Player::levelup() {return level+1;}

    
Player::~Player(){}

Player::Player(){
    level = 1;
    set_HP(50);
    set_strength(1);
    set_armour(0);
    set_e_damage(5);
  }

int Player::damage() {return (HP-= e_damage);}




