#include <iostream>
#include <string>



#include "Item.h"

    Item::Item(){

        std::string item_name;
        int price;
        int level_needed;
        

    }
 
    Item::Item(std::string n, int p, int ln){
        item_name = n;
        price = p;
        level_needed = ln;
        

    }

    std::string Item::get_item_name() {return item_name;}

    int Item::get_price() {return price;}

    int Item::get_level_needed() {return level_needed;}





Item::~Item(){}