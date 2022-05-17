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
    
    bool is_turn;
    int num_turns;
    std::string action_battle[4] = {"show inventory", "attack", "run away", "use item"};
    int action_battle_choice;
    std::string action_story[4] = {"quit", "show inventory", "find enemy", "go ahead"};
    int action_story_choice;
    
    bool is_op_killed;
    
    bool is_battle;
    void Scenario();
    
    ~System();
};
#endif









