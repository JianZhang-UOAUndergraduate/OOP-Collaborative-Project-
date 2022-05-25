#ifndef SYSTEM_H
#define SYSTEM_H

#include <array>
#include <string>

//class definition of system
class System
{
public:
    System();
    System(std::string temp_map_name, bool temp_is_battle);
    std::string map_name;
    void Scenario();
    
protected:
    bool is_turn;//if player turn
    int num_turns;//turn counter
    
    //in combat actions
    //std::string action_battle[6] = {"show inventory", "attack", "run away", "use item", "save", "load"};
    std::string action_battle_choice;//actions
    
    //out combat actions
    //std::string action_story[7] = {"quit", "show inventory", "find enemy", "go ahead", "save", "load"};
    std::string action_story_choice;//actions
    
    bool is_op_killed;//if enemy is killed
    
    bool is_battle;//if in battle
    
    //save_load function
    void Save(int e_HP_origin, int p_HP_origin); 
    void Load();
    int e_HP_destination, p_HP_destination;

    ~System();
};
#endif















