#include <iostream>
#include <string>
#include "Item.h"
#include "Player.h"

using namespace std;

class Weapon : public Item
{
private:
  int raw_damage;
  int final_damage = 0;
public:

  Weapon(int d, std::string n, int p, int ln) :raw_damage(d), Item(n, p, ln) {}

  int get_raw_damage() {return raw_damage;}

  void use(Enemy* e){

    e->set_p_damage(get_raw_damage());

  }

  
  void print(void) { std::cout << get_item_name() << ": " << get_price() << " " << get_level_needed() << " " << raw_damage << "(price, min_level, raw_damage)" <<std::endl; }
};


