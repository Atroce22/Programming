#pragma once
#include <string>

class Equipment
{
public:
	Equipment() {}
	Equipment(int dmg);
	int get_damage();
private:
	std::string name;
	int weight = 0;
	int price = 0;
	int damage = 0;
};
