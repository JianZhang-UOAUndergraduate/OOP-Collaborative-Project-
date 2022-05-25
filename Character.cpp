#include "Character.h"
using namespace std;

// functions related to the mother class Character

int Character::check_armour() {cout <<"armour: "; return armour; cout << endl;}

void Character::show_stats() {
  cout <<"Name: "<< name << endl;
  cout <<"HP: "<< HP << endl;
  cout <<"Strength: " << strength;
cout << endl;
  }
Character::~Character(){}
Character::Character(){
    name = "unknown";
    HP = 20;
    strength = 1;
    armour = 0;
    p_damage = 1;
    e_damage = 1;
  }
bool Character::if_die(){
    if(HP>0)
    return false;
    else 
    return true;
}
void Character::add_stats() {
  HP= HP+1;
  strength= strength+1;
}
