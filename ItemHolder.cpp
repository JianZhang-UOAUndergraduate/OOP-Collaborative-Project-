#include <iostream>
#include <string>
#include <vector>

#include "ItemHolder.h"
#include "Item.h"


    ItemHolder::ItemHolder(){

        std::string Holder_name;
        int Max_item;
        vector<Item*> items;

    }
 


    ItemHolder::ItemHolder(std::string holder_name, int max_Item){
        Holder_name = holder_name;
        Max_item = max_Item;
        

    }





ItemHolder::~ItemHolder(){}