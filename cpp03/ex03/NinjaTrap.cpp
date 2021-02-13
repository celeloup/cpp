#include "NinjaTrap.hpp"
#include <iostream>

#include <sstream>
#include <string>
#include <stdlib.h>

void	NinjaTrap::initialisation()
{
	this->_hitPoints = 60;
	this->_maxHitPoints = 60;
	this->_energyPoints = 120;
	this->_maxEnergyPoints = 120;
	this->_level = 1;
	this->_meleeAttackDamage = 60;
	this->_rangedAttackDamage = 5;
	this->_armorDamageReduction = 0;
}

// CONSTRUCTEURS

NinjaTrap::NinjaTrap() : ClapTrap() {
	initialisation();
	std::cout << "\e[2m[ NINJ4-TP " << this->_name << " is born ! ]\e[0m" << std::endl << std::endl;
	srand(time(NULL));
}

NinjaTrap::NinjaTrap(std::string name) : ClapTrap(name) {
	initialisation();
	std::cout << "\e[2m[ NINJ4-TP " << name << " is born ! ]\e[0m" << std::endl << std::endl;
	srand(time(NULL));
}

NinjaTrap::NinjaTrap(NinjaTrap const & src) : ClapTrap(src) {}

NinjaTrap::~NinjaTrap() {
	std::cout << "\e[2m[ NINJ4-TP " << this->_name << " is gone... ]\e[0m" << std::endl;
}

NinjaTrap &		NinjaTrap::operator=(NinjaTrap const & src)
{
	std::cout << "\e[2m[ NINJ4-TP assigned ]\e[0m" << std::endl << std::endl;
	if (this == &src)
		return (*this);
	this->_hitPoints = src._hitPoints;
	this->_maxHitPoints = src._maxHitPoints;
	this->_energyPoints = src._energyPoints;
	this->_maxEnergyPoints = src._maxEnergyPoints;
	this->_level = src._level;
	this->_name = src._name;
	this->_meleeAttackDamage = src._meleeAttackDamage;
	this->_rangedAttackDamage = src._rangedAttackDamage;
	this->_armorDamageReduction = src._armorDamageReduction;
	return (*this);
}

// FONCTIONS MEMBRES

void NinjaTrap::ninjaShoebox(NinjaTrap &target) {
	if (this->_energyPoints >= 40)
	{
		this->_energyPoints -= 40;
		std::cout << "NINJ4-TP " << this->_name << " attacks a NINJ4-TP !" << std::endl;
		std::cout << "  |д･)    - Yataaa ! You can't even see where my attacks are coming from !" << std::endl << std::endl;
		target.takeDamage(50);
	}
	else
		std::cout << "\e[2m[ NINJ4-TP must rest. This is the way ]\e[0m" << std::endl << std::endl;
}

void NinjaTrap::ninjaShoebox(ClapTrap &target) {
	if (this->_energyPoints >= 40)
	{
		this->_energyPoints -= 40;
		std::cout << "NINJ4-TP " << this->_name << " attacks CL4P-TP !" << std::endl;
		std::cout << "  |д･)    - Father you must die !" << std::endl << std::endl;
		target.takeDamage(50);
	}
	else
		std::cout << "\e[2m[ NINJ4-TP must rest. This is the way ]\e[0m" << std::endl << std::endl;
}

void NinjaTrap::ninjaShoebox(FragTrap &target) {
	if (this->_energyPoints >= 40)
	{
		this->_energyPoints -= 40;
		std::cout << "NINJ4-TP " << this->_name << " attacks FR4G-TP !" << std::endl;
		std::cout << "  |д･)    - Brother you are no match for me !" << std::endl << std::endl;
		target.takeDamage(50);
	}
	else
		std::cout << "\e[2m[ NINJ4-TP must rest. This is the way ]\e[0m" << std::endl << std::endl;
}

void NinjaTrap::ninjaShoebox(ScavTrap &target) {
	if (this->_energyPoints >= 40)
	{
		this->_energyPoints -= 40;
		std::cout << "NINJ4-TP " << this->_name << " attacks SC4V-TP !" << std::endl;
		std::cout << "  |д･)    - Sister, be ready to suffer !" << std::endl << std::endl;
		target.takeDamage(50);
	}
	else
		std::cout << "\e[2m[ NINJ4-TP must rest. This is the way ]\e[0m" << std::endl << std::endl;
}