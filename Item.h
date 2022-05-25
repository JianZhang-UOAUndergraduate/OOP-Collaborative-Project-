#ifndef Item_h
#define Item_h


#include <iostream>
#include <string>
//#include "Player.h"
#include "Enemy.h"


class Item{
private:
    std::string item_name;
    int price;
    int level_needed;
public:
    Item();
    Item(std::string item_name, int price, int level_needed); 

    std::string get_item_name();
    int get_price();
    int get_level_needed();

    virtual void print() = 0 ;  
    virtual void use(Enemy* e) = 0;

    //~Item();

    virtual ~Item();

};




#endif