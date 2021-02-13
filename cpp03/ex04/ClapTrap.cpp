#include "ClapTrap.hpp"
#include <iostream>

#include <sstream>
#include <string>
#include <stdlib.h>

// CONSTRUCTEURS

ClapTrap::ClapTrap() {
		std::cout << "\e[2m[ CL4P-TP created ]\e[0m" << std::endl;
		this->_name = "Albert";
		srand(time(NULL));
	}

ClapTrap::ClapTrap(std::string name) : _name(name) {
		std::cout << "\e[2m[ CL4P-TP " << name << " created ]\e[0m" << std::endl;
		srand(time(NULL));
	}

ClapTrap::ClapTrap(ClapTrap const & src) {
	std::cout << "\e[2m[ CL4P-TP copied ]\e[0m" << std::endl;
	*this = src;
	return ;
}

ClapTrap::~ClapTrap() {
	std::cout << "\e[2m[ CL4P-TP " << this->_name << " destroyed ]\e[0m" << std::endl << std::endl;
}

ClapTrap &		ClapTrap::operator=(ClapTrap const & src)
{
	std::cout << "\e[2m[ CL4P-TP assigned ]\e[0m" << std::endl;
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

void ClapTrap::rangedAttack(std::string const & target) {
	std::cout << this->_name << " used RANGED ATTACK on " << target << std::endl;
	std::cout << "  (　･ω･)っ≡つ     - Yeehaaw !" << std::endl;
	std::cout << "Causing " << this->_rangedAttackDamage << " points of damage." << std::endl << std::endl;
}

void ClapTrap::meleeAttack(std::string const & target) {
	std::cout << this->_name << " used MELEE ATTACK on " << target << std::endl;
	std::cout << "  o(・_・)9     - Come get a taste of my fists !" << std::endl;
	std::cout << "Causing " << this->_meleeAttackDamage << " points of damage." << std::endl << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	amount -= this->_armorDamageReduction;
	if (amount > this->_hitPoints)
		this->_hitPoints = 0;
	else
		this->_hitPoints -= amount;
	std::cout << " > " << this->_name << " looses " << amount << " PV !" << std::endl << std::endl;
	if (this->_hitPoints <= 0)
	{	std::cout << "     " << this->_name << " died." << std::endl;
		std::cout << "  |----------------|" << std::endl;
		std::cout << "  |       __       |" << std::endl;
		std::cout << "  |      |  |      |" << std::endl;
		std::cout << "  |   ___|  |___   |" << std::endl;
		std::cout << "  |  [___    ___]  |" << std::endl;
		std::cout << "  |      |  |      |" << std::endl;
		std::cout << "  |      |  |      |" << std::endl;
		std::cout << "  |      |  |      |" << std::endl;
		std::cout << "  |      |__|      |" << std::endl;
		std::cout << "  |                |" << std::endl;
		std::cout << "  |---- PRESS F ---|" << std::endl << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hitPoints <= 0)
	{
		std::cout << "\e[2m[ " << this->_name << " has left this world. No reparations will fix that ... ]\e[0m" << std::endl << std::endl;
		return ;
	}	
	std::cout << "\e[2m[ " << this->_name << " is making some reparations ! ";
	if (this->_hitPoints == _maxHitPoints)
		std::cout << "But there's nothing to repair !]\e[0m" << std::endl << std::endl;
	else if (this->_hitPoints + amount >= this->_maxHitPoints)
		this->_hitPoints = this->_maxHitPoints;
	else
		this->_hitPoints += amount;
	std::cout << "Back to " << this->_hitPoints << " PV (+" << amount << ") ]\e[0m" << std::endl << std::endl;
}
