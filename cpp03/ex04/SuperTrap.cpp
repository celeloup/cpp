#include "SuperTrap.hpp"
#include <iostream>

#include <sstream>
#include <string>
#include <stdlib.h>

void	SuperTrap::initialisation()
{
	this->_hitPoints = FragTrap::_hitPoints;
	this->_maxHitPoints = FragTrap::_maxHitPoints;
	this->_energyPoints = NinjaTrap::_energyPoints;
	this->_maxEnergyPoints = NinjaTrap::_maxEnergyPoints;
	this->_level = 1;
	this->_meleeAttackDamage = NinjaTrap::_meleeAttackDamage;
	this->_rangedAttackDamage = FragTrap::_rangedAttackDamage;
	this->_armorDamageReduction = FragTrap::_armorDamageReduction;
}

// CONSTRUCTEURS

SuperTrap::SuperTrap() : ClapTrap(), FragTrap(), NinjaTrap()
{
	initialisation();
	std::cout << "\e[2m[ SUPER-TP " << this->_name << " arise ! ]\e[0m" << std::endl << std::endl;
	return ;
}

SuperTrap::SuperTrap(std::string name) : ClapTrap(name), FragTrap(name), NinjaTrap(name) {
	initialisation();
	std::cout << "\e[2m[ SUPER-TP " << this->_name << " arise ! ]\e[0m" << std::endl << std::endl;
	srand(time(NULL));
}

SuperTrap::SuperTrap(SuperTrap const & src) : FragTrap(src), NinjaTrap(src) {}

SuperTrap::~SuperTrap() {
	std::cout << "\e[2m[ SUPER-TP " << this->_name << " says goodbye... ]\e[0m" << std::endl;
}

SuperTrap &		SuperTrap::operator=(SuperTrap const & src)
{
	std::cout << "\e[2m[ SUPER-TP assigned ]\e[0m" << std::endl << std::endl;
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

void		SuperTrap::rangedAttack(std::string const &target)
{
	FragTrap::rangedAttack(target);
	return ;
}

void		SuperTrap::meleeAttack(std::string const &target)
{
	NinjaTrap::meleeAttack(target);
	return ;
}
