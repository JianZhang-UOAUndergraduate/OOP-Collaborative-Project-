#include <iostream>
#include <string>
#include <fstream> 
#include "System.h"
#include "Item.h"
#include "ItemHolder.h"
#include "Weapon.cpp"
#include "Player.h"
#include "Enemy.h"
#include "Character.h"
#include "Armour.cpp"

//implamentation of the system
System::System()
{
    map_name = "?";
    is_turn = 0;
    num_turns = 1;
    is_battle = 0;
    action_battle_choice = "0";
    action_story_choice = "0";
}

//sample implamentation of the system
System::System(std::string temp_map_name, bool temp_is_battle)
{
    map_name = temp_map_name;
    is_turn = 0;
    num_turns = 1;
    is_battle = 0;
    action_battle_choice = "0";
    action_story_choice = "0";
    is_battle = temp_is_battle;
}

//actions
void System::Scenario()
{
    

    //create the player and a enemy object
    Enemy*e = new Enemy();
    Player* p = new Player();

    

    //Create the player inventory and add a sword to it.
    ItemHolder player_inventory;


    Weapon * sword = new Weapon(5,"SWORD",3,0);

    Armour * arm = new Armour(3,"Armofrgutio",3,0);
    //Armour Armour_default(3,"Armour_default",2,0);

    player_inventory.items.push_back(sword);

    player_inventory.items.push_back(arm);

    std::string name;
    std::cout << "Please type your name."<< std::endl;
    std::cin >> name;
    p->set_name(name);
    
    start_label:
    
    //action out battle
    while (is_battle == 0) {
        
        std::cout << "Hi, " << p->get_name() << "! You are in " << map_name << " you can choose to: ";
        std::cout << "quit" << "(press 1) " << "or " << "Show Inventory" << "(press 2) " << "or " << "find enemy";
        std::cout << "(press 3) or " << "go ahead" << " (Press 4)." << std::endl;
        std::cout << "Save " << "(Press 5) " << "Load " << "(Press 6)" << std::endl;
        std::cin >> action_story_choice;
        
        //wrong input
        while (action_story_choice != "1" && action_story_choice != "2" && action_story_choice != "3" && action_story_choice != "4" && action_story_choice != "5" && action_story_choice != "6"){
            std::cout << "Error! Enter again:" << std::endl;
            std::cin >> action_story_choice;
        }
        
        //show inventory
        if (action_story_choice == "2") {
            std::cout << "inventory" << std::endl;
            //list up items in the inventory
            for (int i = 0; i < player_inventory.items.size(); i++)
                player_inventory.items[i] -> print();
        }
            
        //find enemy
        else if (action_story_choice == "3") {
            is_battle = 1;
        } else if (action_story_choice == "1") {//quit game
            is_battle = 0;
            delete p,e, sword, arm;
            break;
        } else if (action_story_choice == "5") {//save game
            System::Save(e->get_HP(), p->get_HP());
            std::cout << "Game saved."<< std::endl;
        } else if (action_story_choice == "6") {//load game
            System::Load();
            e->set_HP(e_HP_destination); 
            p->set_HP (p_HP_destination);
        }
    }
    
    //encounter enemy
    if (is_battle == 1) {
            std::cout << "You encounter an enemy!" << std::endl;
            arm->use(e);
            //e->show_stats()
            is_turn = 1;//player turn
        } else {
            is_turn = 0;//not player turn
            num_turns = 1;//reset counter
        }

    //actions in battle
    while (is_battle == 1) {
        
        //enemy die
        if (e->get_HP() <= 0 ){
                is_battle = 0; //go back to menu
                is_turn = 0;//reset turn
                num_turns = 1;//reset counter
                //gold->price += 3;
                e->set_HP(20);//reset enemy hp
                std::cout << "Enemy defeated! "  << std::endl;
                //std::cout << "You have " <<  gold->price << " golds now." << std::endl;
                p->set_HP(50);
                goto start_label;//run the game again
            }
        
        //battle system
        switch(is_turn){
        case 1: //player turn
            std::cout << "Turn " << num_turns << std::endl;
            std::cout << "This is your turn, choose: " << "Show Inventory" << "(1)";
            std::cout << " or " <<  "attack" << "(2)";
            std::cout << " or " <<  "run away" << "(3)";
            std::cout << " or " <<  "use item" << "(4)" << std::endl;
            std::cout << "Save" << " (Press 5) or " << " Load " << "(Press 6)" << std::endl;
            
            std::cin >> action_battle_choice;
            
            //wrong input
            while (action_battle_choice != "1" && action_battle_choice != "2" && action_battle_choice != "3" && action_battle_choice != "4" && action_battle_choice != "5" && action_battle_choice != "6"){
                std::cout << "Error! Enter again:" << std::endl;
                std::cin >> action_battle_choice;
            }
            
            //show inventory
            if (action_battle_choice == "1") {
                std::cout << "inventory" << std::endl;
                //list up items in the inventory
                for (int i = 0; i < player_inventory.items.size(); i++)
                    player_inventory.items[i] -> print();
            
            //attack
            } else if (action_battle_choice == "2") {
                    std::cout << "You attacked the enemy!" << std::endl;
                    sword->use(e);
                    e->damage();
                    std::cout <<"player's HP: "<< p->get_HP() << endl;
                    std::cout <<"enemy's HP: "<< e->get_HP() << endl;
                    is_turn = 0;//enemy turn
                    num_turns++;//increase turn counter
            //run
            } else if (action_battle_choice == "3") {
                    std::cout << "You ran away!" << std::endl;
                    num_turns = 1;
                    is_battle = 0;
                    p->set_HP(50);
                    goto start_label;//go back to the beginning of the loop
            
            //use item
            } else if (action_battle_choice == "4") {
                    std::cout << "You used an item!" << std::endl;
            } else if (action_battle_choice == "5") {//save
                System::Save(e->get_HP(), p->get_HP());
                std::cout << "Game saved."<< std::endl;

                
            } else if (action_battle_choice == "6") {//load
                System::Load();
                e->set_HP(e_HP_destination); //set the hp of player and enemy to equal the data stored in System::Load()
                p->set_HP(p_HP_destination);
                if (is_battle == 0) {
                    goto start_label;
                }
            }
        
        break;
            
        case 0://enemy turn
            std::cout << "Enemy turn: "; 
            std::cout << "he attacked you!" << std::endl;
            std::cout << "strength:" << e->get_strength()<< std::endl;
            p->set_HP(p->get_HP() - e->get_strength() + e->get_damage_decay());
            std::cout <<"player's HP: "<< p->get_HP() << endl;
            std::cout <<"enemy's HP: "<< e->get_HP() << endl;
            is_turn = 1;
        break;
        }
    }

}

//save function
void System::Save(int e_HP_origin, int p_HP_origin) {
    //cloning the variables
    int Enemy_HP = e_HP_origin;
    int Player_HP = p_HP_origin;
    int saved_is_turn = is_turn;
    int saved_num_turns = num_turns;
    int saved_is_battle = is_battle;
    
    //create savefile
    std::ofstream outfile("save.txt");
    outfile << Enemy_HP << " " << Player_HP << " " << saved_is_turn << " " << saved_num_turns << " " << saved_is_battle << std::endl;
    
    outfile.close();
}

//load function
void System::Load() {
    //creating a string that stores saved variables
    std::string bin;
    std::string temp_Enemy_HP;
    std::string temp_Player_HP;
    std::string temp_saved_is_turn;
    std::string temp_saved_num_turns;
    std::string temp_saved_is_battle;
    
    std::ifstream infile("save.txt");
    getline(infile, bin);// take in the saved variables
    
    
    //loop to take in the saved variables
    int i = 0;
    while (bin[i] != ' ') {
        temp_Enemy_HP += bin[i];
        i++;
    }
    i++;
    while (bin[i] != ' ') {
        temp_Player_HP += bin[i];
        i++;
    }
    i++;
    while (bin[i] != ' ') {
        temp_saved_is_turn += bin[i];
        i++;
    }
    i++;
    while (bin[i] != ' ') {
        temp_saved_num_turns += bin[i];
        i++;
    }
    i++;
    while (bin[i] != ' ') {
        temp_saved_is_battle += bin[i];
        i++;
    }
    i = 0;
    
    //load statistics
    e_HP_destination = stoi(temp_Enemy_HP);
    p_HP_destination = stoi(temp_Player_HP);
    is_turn = stoi(temp_saved_is_turn);
    num_turns = stoi(temp_saved_num_turns);
    is_battle = stoi(temp_saved_is_battle);
}


System::~System()
{
}
