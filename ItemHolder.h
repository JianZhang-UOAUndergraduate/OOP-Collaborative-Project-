#ifndef ItemHolder_h    
#define ItemHolder_h

#include <iostream>
#include <string>
#include <vector>

using std::vector;

#include "Item.h"


class ItemHolder{
public:
    ItemHolder(); 
    std::string Holder_name;
    int Max_item;
    vector<Item*> items;
    ItemHolder(std::string holder_name, int max_Item); 

    

    // void add_item(item*);
    // void remove_item();

    ~ItemHolder();  

};

#endif 
