#include <iostream>
#include <string>
#include "Item.h"
#include "Player.h"

class Armour : public Item
{
private:
  int damage_deduct;

public:

  Armour(int d, std::string n, int p, int ln) :damage_deduct(d), Item(n, p, ln) {}

  int get_damage_deduct(){

    return damage_deduct;
  }

  //prints out the armour
  void print(void) { std::cout << get_item_name() << ": " << get_price() << " " << get_level_needed() << " " << get_damage_deduct() << "(price, min_level, damage_deduct)" <<std::endl; }

  void use(Enemy* e){

    e->set_damage_decay(get_damage_deduct());

  }
};


