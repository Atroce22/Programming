#include "Equipment.h"
#include <iostream>

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
	try
	{
		if (value < 0)
			throw -1;
		if (value >= 1000)
			throw std::string("Too much damage");
		damage = value;
	}
	catch(int a)
	{
		std::cerr << "We caught an int exception with value: " << a << ". Reset damage to 0\n";
		damage = 0;
	}
	catch (const std::string& str)
	{
		std::cerr << "We caught an exception of type std::string. Message: "<< str << ". Reset damage to 999\n";
		damage = 999;
	}
}