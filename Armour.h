#ifndef Armour_H
#define Armour_H

#include <iostream>
#include <string>
#include "Item.h"
#include "Player.h"

class Armour : public Item
{
private:
  int damage_deduct;
public:
  Armour();
  
  Armour(int d, std::string n, int p, int ln) :damage_deduct(d), Item(n, p, ln) {}

  //returns damage_deduct
  int get_damage_deduct();

  //prints out stats of the armmour
  void print(); 

  
  void use(Enemy* e);

  ~Armour();
};





#endif
