#include "Class.h"
using namespace std;

// functions related to the mother class Character

int Character::check_armour() {cout <<"armour: "; return armour; cout << endl;}

int Character::show_stats() {
  cout <<"Name: "<< name << endl;
  cout <<"HP: "<< HP << endl;
  cout <<"Strength: ";
  return strength;
cout << endl;
  }
Character::~Character(){}
Character::Character(){
    name = "unknown";
    HP = 20;
    strength = 1;
    armour = 0;
    given_experience = 0;
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

// functions related to the child class Player

void Player::attacked_by(Character*){ this->HP -=1;}

void Player::levelup() {if(experience=100) level= level+1;}
void Player::add_experience() {if(HP==0) 
    experience = 100;
    }

Player::Player(){
    level = 1;
    experience = 0;
    HP = 20;
    strength = 1;
    armour = 0;
    given_experience = 0;
   
  }


// functions related to the child class Enemy
Enemy::Enemy(){ 
    name="monster"; 
    e_level=1;
    HP = 20;
    strength = 2;
    armour = 0;
  
    }

void Enemy::e_levelup() {if(given_experience=100) e_level = e_level+1;}
void Enemy::balance_stats(){if(HP>0) 
    given_experience = 100; 
    else Character();};

void Enemy::attacked_by(Character*){ this->HP -=1;}

