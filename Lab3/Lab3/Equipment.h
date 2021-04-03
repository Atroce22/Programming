#pragma once
#include <string>
class Equipment
{
public:
	Equipment() {}
	Equipment(int dmg, std::string weapon = "");
	int get_damage();
	void set_damage(int value);
	std::string get_name();
	Equipment operator + (const Equipment& b) { Equipment weapon; weapon.damage = this->damage + b.damage; return weapon; }
private:
	std::string name;
	int weight = 0;
	int price = 0;
	int damage = 0;
};
