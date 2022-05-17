#include <iostream>
#include "System.h"
#include "Item.h"
#include "ItemHolder.h"
#include "Weapon.cpp"
#include "Class.h"

//implamentation of the system
System::System()
{
    map_name = "?";
    is_turn = 0;
    num_turns = 0;
    action_battle_choice = 0;
    action_story_choice = 0;
}

System::System(std::string temp_map_name, bool temp_is_battle)
{
    map_name = temp_map_name;
    is_turn = 0;
    num_turns = 0;
    action_battle_choice = 0;
    action_story_choice = 0;
    is_battle = temp_is_battle;
}

//actions
void System::Scenario()
{
    start_label:

    //create the player and a enemy object
    Enemy*e = new Enemy();
    Player* p = new Player();
    p->set_name("Adventurer");

    //Create the player inventory and add a sword to it.
    ItemHolder player_inventory;


    Weapon * sword = new Weapon(5,"SWORD",3,0);

    //Item * gold = new Item("gold", 0, 0);
    
    

    
    player_inventory.items.push_back(sword);


    while (is_battle == 0) {
        std::cout << "Hi! You are in " << map_name << " you can choose to: ";
        std::cout << action_story[0] << "(press 1) " << "or " << action_story[1] << "(press 2) " << "or " << action_story[2];
        std::cout << "(press 3) or " << action_story[3] << " press(4)." << std::endl;
        std::cin >> action_story_choice;
        while (action_story_choice > 4 || action_story_choice < 1){
            std::cout << "Error! Enter again:" << std::endl;
            std::cin >> action_story_choice;
        }
        
        if (action_story_choice == 2) {
            std::cout << "inventory" << std::endl;
            //list up items in the inventory
            for (int i = 0; i < player_inventory.items.size(); i++)
                player_inventory.items[i] -> print();
        }
            


        if (action_story_choice == 3) {
            is_battle = 1;
        } else if (action_story_choice == 1) {
            break;
        }
    }
    
    if (is_battle == 1) {
            std::cout << "You encounter an enemy!" << std::endl;
            is_turn = 1;
            num_turns++;
        } else {
            is_turn = 0;
            num_turns = 0;
        }
    while (is_battle == 1) {
        
        if (e->HP <= 0 ){
                is_battle = 0;
                is_turn = 0;
                num_turns = 0;
                //gold->price += 3;
                e->HP = 20;
                std::cout << "Enemy defeated! "  << std::endl;
                //std::cout << "You have " <<  gold->price << " golds now." << std::endl;
                System::Scenario();
            }
        
        switch(is_turn){
            case 1: //player turn
            std::cout << "Turn " << num_turns << std::endl;
            std::cout << "This is your turn, choose: " << action_battle[0] << "(1)";
            std::cout << " or " << action_battle[1] << "(2)";
            std::cout << " or " << action_battle[2] << "(3)";
            std::cout << " or " << action_battle[3] << "(4)" << std::endl;
            
            std::cin >> action_battle_choice;
            while (action_battle_choice > 4 || action_battle_choice < 1) {
                std::cout << "Error! Try again: " << std::endl;
                std::cin >> action_battle_choice;
            }
            
            if (action_battle_choice == 1) {
                std::cout << "inventory" << std::endl;
                //list up items in the inventory
                for (int i = 0; i < player_inventory.items.size(); i++)
                    player_inventory.items[i] -> print();

            } else if (action_battle_choice == 2) {
                    std::cout << "You attacked the enemy!" << std::endl;
                    e->HP -= sword->raw_damage;
                    cout <<"player's HP: "<< p->get_HP() << endl;
                    cout <<"enemy's HP: "<< e->get_HP() << endl;

            } else if (action_battle_choice == 3) {
                    std::cout << "You ran away!" << std::endl;
                    num_turns = 0;
                    is_battle = 0;
                    goto start_label;
            } else if (action_battle_choice == 4) {
                    std::cout << "You used an item!" << std::endl;
            }
            num_turns++;
            is_turn = 0;
            break;
            
            case 0://enemy turn
            std::cout << "Enemy turn: "; 
            std::cout << "he attacked you!" << std::endl;
            p->HP -= e->strength;
            cout <<"player's HP: "<< p->get_HP() << endl;
            cout <<"enemy's HP: "<< e->get_HP() << endl;
            is_turn = 1;
            break;
        }
    }

}


System::~System()
{
}








