#ifndef Item_h
#define Item_h


#include <iostream>
#include <string>

class Item{
public:
    Item();
    std::string item_name;
    int price;
    int level_needed;
    Item(std::string item_name, int price, int level_needed); 
    virtual void print() {};
    
    ~Item();

};




#endif