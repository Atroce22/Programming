#pragma once
#include "Equipment.h"
#include <string>
#include <vector>
#include <iostream>
static const std::vector<std::string> names = { "Lo Whitbottom", "Meginhard Swiftfoot", "Godomar Gawkroger", "Gerontius Chubb - Baggins", "Walcaud Leafwalker", "Griffon Harfoot", "Balbo Sackville", "Butilin Lothran", "Willehad Silverstring", "Berengar Undertree" };
static const std::vector<std::string> races = { "Human", "Orc", "Elf", "Hobbit", "Charr", "Norn" };
class Character
{
public:
    virtual ~Character() { std::cout << name <<" Destroyed!\n"; };
    Character(const std::string& name, const std::string& race, int level, Equipment* left, Equipment* right);
    Character(const std::string& name);
    Character();
    Character(const Character& character);
    Character& operator = (const Character& character)
    {
        name = character.name;
        race = character.race;
        level = character.level;
        id = character.id;
        update_data();
        return *this;
    }
    static std::string read();
    void display();
    void level_up();
    void add(int exp);
    void take_damage(int dmg);

    std::string get_race();
    int get_level();
    int get_health();
    int get_mana();
    int get_experience();
    int get_damage();
    Equipment* get_left_hand();
    Equipment& get_right_hand();
    Character& operator ++() 
    { 
        level_up(); 
        return *this; 
    }
    Character operator ++(int) 
    { 
        Character temp = *this;
        //++*this;
        level_up();
        return temp; 
    }

    friend void reset_level(Character& character);
    static void display(Character* character);
    static int get_counter();

private:
    void update_data();
    int get_equipment_damage();

private:
    std::string name;
    std::string race;
    int level = 0;
    int health = 0;
    int mana = 0;
    int experience = 0;
    float damage = 0;
    bool dead = false;
    int id = 0;
    static int counter ;

    Equipment* left_hand = nullptr;
    Equipment* right_hand = nullptr;


}; 

static void reset_level(Character& character)
{
    character.level = 1;
    character.update_data();
}