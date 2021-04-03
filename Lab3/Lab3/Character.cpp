#define _CRT_SECURE_NO_WARNINGS
#include "Character.h"
#include <iostream>
#include <ctime>

int Character::counter = 0;

Character::Character(const std::string& name, const std::string& race, int level, Equipment* left, Equipment* right)
{
    this->name = name;
    this->race = race;
    this->level = level;
    left_hand = left;
    right_hand = right;
    id = counter++;
    update_data();
}

Character::Character(const std::string& name)
{
    this->name = name;
    race = races[std::rand() % races.size()];
    level = std::rand() % 10 + 1;
    left_hand = new Equipment(std::rand() % 10 + 1);
    right_hand = new Equipment(std::rand() % 10 + 1);
    id = counter++;
    update_data();
}

Character::Character()
{
    name = names[std::rand() % names.size()];
    race = races[std::rand() % races.size()];
    level = std::rand() % 10 + 1;
    left_hand = new Equipment(std::rand() % 10 + 1);
    right_hand = new Equipment(std::rand() % 10 + 1);
    id = counter++;
    update_data();
}

Character::Character(const Character& character) : id(character.id), name(character.name), race(character.race), level(character.level), left_hand(new Equipment(*character.left_hand)), right_hand(character.right_hand)
{
    update_data();
}

int Character::get_counter()
{
    return counter;
}

std::string Character::read()
{
    std::cout << "Input character name: ";
    std::string s;
    std::cin >> s;
    return s;
}

void Character::display(Character* character)
{
    character->display();
}


void Character::display()
{
    std::cout << "ID: "<< id << "\nName: " << name << "\nRace: " << race << "\nLevel: " << level << "\nExperience: " << experience << " \/ 100" << "\nHealth: " << health << "\nMana: " << mana << "\nDamage: " << get_damage() << " (" << damage << "+" << get_equipment_damage() << ")"   << "\n";
    if (left_hand != nullptr && left_hand->get_name() != "")
    {
        std::cout << left_hand->get_name() << ": " << left_hand->get_damage() << std::endl;
    }
    if (right_hand != nullptr && right_hand->get_name() != "")
    {
        std::cout << right_hand->get_name() << ": " << right_hand->get_damage() << std::endl;
    }
    std::cout << std::endl;
}


void Character::level_up()
{
    level++;
    update_data();
}

void Character::add(int exp)
{
    experience += exp;
    while (experience >= 100)
    {
        experience -= 100;
        level_up();
    }
}


void Character::take_damage(int dmg)
{
    health -= dmg;
    if (health <= 0)
    {
        health = 40 * level;
        experience = 0;
        dead = true;
        std::cout << "You're dead" << std::endl;
    }
}


void Character::update_data()
{
    health = 40 * level;
    mana = 20 * level;
    damage = 5 * level;
}

std::string Character::get_race()
{
    return race;
}

int Character::get_equipment_damage()
{
    if (left_hand != nullptr && right_hand != nullptr)
        return ((*left_hand) + (*right_hand)).get_damage();
    return 0;
}

int Character::get_damage()
{
    return damage + get_equipment_damage();
}

int Character::get_experience()
{
    return experience;
}

int Character::get_health()
{
    return health;
}

int Character::get_level()
{
    return level;
}

int Character::get_mana()
{
    return mana;
}

Equipment* Character::get_left_hand()
{
    return left_hand;
}
Equipment& Character::get_right_hand() 
{
    return *right_hand;
}



