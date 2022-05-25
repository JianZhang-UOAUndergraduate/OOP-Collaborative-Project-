#ifndef Enemy_h
#define Enemy_h

#include <iostream>
#include <string>
#include "Character.h"
using namespace std;

class Enemy : public Character {


private:
  int damage_decay;

public:
  Enemy(){ 
      set_name("monster"); 
      set_HP(20);
      set_strength(2);
      set_armour(0);
      set_p_damage(1);
      }

  int damage();

  int get_damage_decay();

  void set_damage_decay(int dacay_value);

  //~Enemy();

  //virtual ~Enemy(){

  //};



  };
#endif
