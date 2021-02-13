#include "FragTrap.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>

// CONSTRUCTEURS

FragTrap::FragTrap() : _hitPoints(100), _maxHitPoints(100), \
	_energyPoints(100), _maxEnergyPoints(100), _level(1), _name("Albert"), \
	_meleeAttackDamage(30), _rangedAttackDamage(20), _armorDamageReduction(5) {
		std::cout << "\e[2m[ FR4G-TP Albert has been SUMMONED ]\e[0m" << std::endl << std::endl;
		srand(time(NULL));
	}

FragTrap::FragTrap(std::string name) :_hitPoints(100), _maxHitPoints(100), \
	_energyPoints(100), _maxEnergyPoints(100), _level(1), _name(name), \
	_meleeAttackDamage(30), _rangedAttackDamage(20), _armorDamageReduction(5) {
		std::cout << "\e[2m[ FR4G-TP " << name << " has been SUMMONED ]\e[0m" << std::endl << std::endl;
		srand(time(NULL));
	}

FragTrap::FragTrap(FragTrap const & src) {
	std::cout << "\e[2m[ FR4G-TP copied ]\e[0m" << std::endl << std::endl;
	*this = src;
	return ;
}

FragTrap::~FragTrap() {
	std::cout << "\e[2m[ FR4G-TP " << this->_name << " has been DESTROYED ]\e[0m" << std::endl;
}

FragTrap &		FragTrap::operator=(FragTrap const & src)
{
	std::cout << "\e[2m[ FR4G-TP assigned ]\e[0m" << std::endl << std::endl;
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

void FragTrap::rangedAttack(std::string const & target) {
	std::cout << this->_name << " used RANGED ATTACK on " << target << std::endl;
	std::cout << "  (　･ω･)っ≡つ     - Yeehaaw !" << std::endl;
	std::cout << "Causing " << this->_rangedAttackDamage << " points of damage." << std::endl << std::endl;
}

void FragTrap::meleeAttack(std::string const & target) {
	std::cout << this->_name << " used MELEE ATTACK on " << target << std::endl;
	std::cout << "  o(・_・)9     - Come get a taste of my fists !" << std::endl;
	std::cout << "Causing " << this->_meleeAttackDamage << " points of damage." << std::endl << std::endl;
}

void FragTrap::takeDamage(unsigned int amount) {
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

void FragTrap::beRepaired(unsigned int amount) {
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

void FragTrap::vaulthunter_dot_exe(std::string const & target) {
	if (this->_energyPoints < 25)
		std::cout << "\e[2m[ " << this->_name << " is out of ENERGY ! Need to take a nap ? ]\e[0m" << std::endl << std::endl;
	else
	{
		this->_energyPoints -= 25;
		
		int index = rand() % 5;
		switch (index)
		{
		case 1:
			hugAttack(target);
			break;
		case 2:
			magicAttack(target);
			break;
		case 3:
			flipTableAttack(target);
			break;
		case 4:
			swagAttack(target);
			break;
		default:
			kamehaAttack(target);
			break;
		}
	}
}

void FragTrap::magicAttack(std::string const & target) {
	std::cout << this->_name << " used MAGIC ATTACK on " << target << std::endl;
	std::cout << "  ੭•̀ω•́)੭̸*✩⁺˚     - Sparkles all over you !" << std::endl;
	std::cout << "Causing 25 points of damage." << std::endl << std::endl;
}

void FragTrap::kamehaAttack(std::string const & target) {
	std::cout << this->_name << " used KAMEHAMEHA ATTACK on " << target << std::endl;
	std::cout << "  ༼つಠ益ಠ༽つ ─=≡ΣO))     - かめはめ 波 は !" << std::endl;
	std::cout << "Causing 105 points of damage." << std::endl << std::endl;
}

void FragTrap::flipTableAttack(std::string const & target) {
	std::cout << this->_name << " used FLIP TABLE ATTACK on " << target << std::endl;
	std::cout << "  (ﾉಠдಠ)ﾉ︵┻━┻     - Tables have turned !" << std::endl;
	std::cout << "Causing 40 points of damage." << std::endl << std::endl;
}

void FragTrap::swagAttack(std::string const & target) {
	std::cout << this->_name << " used SWAG ATTACK on " << target << std::endl;
	std::cout << "  (つ▀¯▀)つ     - You can't handle my swag." << std::endl;
	std::cout << "Causing 65 points of damage." << std::endl << std::endl;
}

void FragTrap::hugAttack(std::string const & target) {
	std::cout << this->_name << " used HUG ATTACK on " << target << std::endl;
	std::cout << "  (づ￣ ³￣)づ     - Come here baby." << std::endl;
	std::cout << "Causing 10 points of damage." << std::endl << std::endl;
}