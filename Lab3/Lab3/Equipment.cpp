#include "Equipment.h"

Equipment::Equipment(int dmg, std::string weapon)
{
	damage = dmg;
	name = weapon;
}

int Equipment::get_damage()
{
	return damage;
}

std::string Equipment::get_name()
{
	return name;
}

void Equipment::set_damage(int value)
{
	damage = value;
}