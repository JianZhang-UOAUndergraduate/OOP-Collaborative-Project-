#include <iostream>
#include <string>

using namespace std;

class Character {
  public:
  string name;
  int HP;
  int strength;
  int armour;
  int given_experience;
  Character();
  ~Character();

  string get_name(){return name;}
  int get_HP(){return HP;}
  int get_strength(){return strength;}
   int get_armour(){return armour;}
  

  void set_name(string new_name) {name = new_name;}
  void set_HP(int new_HP) {HP = new_HP;}
  void set_strength(int new_strength) {strength = new_strength;}
  void set_armour(int new_armour) {armour = new_armour;}
  bool if_die();
 int show_stats();
 int check_armour();
 void add_stats();
};

class Player : public Character{
    public:
    int level;
    int experience;
    Player();
    void levelup();
    void add_experience();
    void attacked_by(Character*);
   
};

class Enemy : public Character {
  public:
  int e_level;
  Enemy();
  void e_levelup();
  void balance_stats();
  void attacked_by(Character*);
  
  };
