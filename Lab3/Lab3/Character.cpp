#define _CRT_SECURE_NO_WARNINGS
#include "Character.h"
#include <iostream>
#include <ctime>

void Character::init(const std::string& name)
{
    this->name = name;
    race = "Human";
    level = 1;
    health = 40;
    mana = 20;
    damage = 5;
    experience = 0;
}

std::string Character::read()
{
    std::cout << "Input character name: ";
    std::string s;
    std::cin >> s;
    return s;
}

void Character::display()
{
    std::cout << "Name: " << name << "\nRace: " << race << "\nLevel: " << level << "\nExperience: " << experience << " \/ 100" << "\nHealth: " << health << "\nMana: " << mana << "\nDamage: " << damage << "\n\n";
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

void Character::init()
{

    name = names[std::rand() % names.size()];
    race = races[std::rand() % races.size()];
    level = std::rand() % 10 + 1;
    update_data();
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

int Character::get_damage()
{
    return damage;
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



