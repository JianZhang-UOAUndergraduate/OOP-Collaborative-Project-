#include <iostream>
#include <string>
#include "Item.h"

class Weapon : public Item
{
public:
  int raw_damage;

  Weapon(int d, std::string n, int p, int ln) :raw_damage(d), Item(n, p, ln) {}

  void print(void) { std::cout << item_name << ": " << price << " " << level_needed << " " << raw_damage << "(price, min_level, raw_damage)" <<std::endl; }
};