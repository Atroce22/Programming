#include "Equipment.h"

Equipment::Equipment(int dmg)
{
	damage = dmg;
}

int Equipment::get_damage()
{
	return damage;
}