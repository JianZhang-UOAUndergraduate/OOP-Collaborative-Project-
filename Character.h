#ifndef Character_h
#define Character_h

#include <iostream>
#include <string>

using namespace std;

class Character {
  protected:
  string name;
  int HP;
  int strength;
  int armour;
  int p_damage;
  int e_damage;
  public:
  Character();
  //~Character();
// functions to access variables
  string get_name(){return name;}
  int get_HP(){return HP;}
  int get_strength(){return strength;}
   int get_armour(){return armour;}
   int get_p_damage(){return p_damage;}
   int get_e_damage(){return e_damage;}
  
// functions to set variables
  void set_name(string new_name) {name = new_name;}
  void set_HP(int new_HP) {HP = new_HP;}
  void set_strength(int new_strength) {strength = new_strength;}
  void set_armour(int new_armour) {armour = new_armour;}
  void set_p_damage(int new_p_damage) {p_damage = new_p_damage;}
  void set_e_damage(int new_e_damage) {e_damage = new_e_damage;}


  bool if_die();
  void show_stats();
  int check_armour();
  void add_stats();
  virtual int damage()=0;

  virtual ~Character();
};

#endif
