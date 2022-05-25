#ifndef Weapon_H
#define Weapon_H

#include <iostream>
#include <string>
#include "Item.h"
#include "Player.h"

class Weapon : public Item
{
public:
  int raw_damage;
public:
  Weapon();
  
  Weapon(int d, std::string n, int p, int ln) :raw_damage(d), Item(n, p, ln) {}

  int get_raw_damage();

  void print(); 

  void use();

  ~Weapon();
};





#endif
