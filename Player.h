#ifndef Player_h
#define Player_h

#include <iostream>
#include <string>
#include "Character.h"
using namespace std;

class Player : public Character{
    private:
    int level;
    int experience;
    public:
    Player();
    
    int levelup();
    int damage();

    ~Player();

   //virtual ~Player();
};
#endif
