#include "Character.h"
#include "Enemy.h"
using namespace std;

// functions related to the child class Enemy


int Enemy::damage() {return (HP-= p_damage);}


int Enemy::get_damage_decay() {return damage_decay;}

void Enemy::set_damage_decay(int dacay_value) {damage_decay = dacay_value;}