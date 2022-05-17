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






Item::~Item(){}