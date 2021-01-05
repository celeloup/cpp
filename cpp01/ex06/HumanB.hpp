#ifndef HUMANB_H
# define HUMANB_H
#include "Weapon.hpp"

class HumanB
{
	public:
	HumanB(std::string name);
	~HumanB();
	void setWeapon(Weapon &weapon);
	void attack();

	private:
	std::string name;
	Weapon *weapon;
};

#endif