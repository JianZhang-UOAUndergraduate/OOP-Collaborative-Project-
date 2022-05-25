#include <iostream>
#include <string>


#include "Item.h"
#include "ItemHolder.h"
#include "Weapon.cpp"
#include "Player.h"
#include "Enemy.h"
#include "Character.h"
#include "System.h"

using namespace std;

int main(){


    //Setup the game system
    System *temp_system;
    temp_system = new System("Dessert", 0);
    
    string on_off; //start or end game
    cout << "Start game? 1: to start, 0: to end." << endl;
    cin >> on_off;
    
    //wrong input
    while (on_off != "1" && on_off != "0") {
        cout << "Error! Try again: " << endl;
        cin >> on_off;
    }
    
    //create system object - start game
    if (on_off == "1") {
        temp_system->Scenario();
    } 


    //create the player and a enemy object
    Enemy*e = new Enemy();
    Player* p = new Player();
    p->set_name("Adventurer");


    //cout <<"player's HP: "<< p->get_HP() << endl;
    //cout <<"enemy's HP: "<< e->get_HP() << endl;

    //cout << p->level << endl;

    //cout << p->check_armour() << endl;
    //cout << e->get_name() << endl;

    return 0; 
}














