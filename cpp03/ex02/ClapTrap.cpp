#include "ClapTrap.hpp"
#include <iostream>

#include <sstream>
#include <string>
#include <stdlib.h>

// UTILS

std::string ClapTrap::toUpper(std::string str)
{
	std::string ret = "";
	unsigned long i = 0;
	while (i < str.length())
	{
		if (str.at(i) >= 'a' && str.at(i) <= 'z')
			ret += str.at(i) - 32;
		else
			ret += str.at(i);
		i++;
	}
	return (ret);
}

void	ClapTrap::printLine(int maxLength, char fill, std::string str, int strLength)
{
	std::string color = "  \e[7m|";
	std::string end = "|\e[0m";

	int fillLength = (maxLength - strLength) / 2;
	std::string fillStr(fillLength, fill);
	if ((maxLength - strLength) % 2 == 0)
		std::cout << color << fillStr << str << fillStr << end << std::endl;
	else
		std::cout << color << fillStr << str << fillStr << fill << end << std::endl;
}

void	ClapTrap::printAttack(std::string attacker, std::string attackName, \
	std::string attack, unsigned long attackLength, std::string points, std::string target)
{
	// CREATING LINES
	std::string firstLine = " " + toUpper(attacker) + " uses " + attackName + " ! ";
	std::string lastLine = " causing " + points + " POINTS of damage to " + toUpper(target) + " ";
	
	// DETERMINATING MAX LENGTH
	unsigned long maxLength = 52;
	if (lastLine.length() > maxLength)
		maxLength = lastLine.length();
	if (firstLine.length() > maxLength)
		maxLength = firstLine.length();
	if ( attackLength > maxLength)
		maxLength = attackLength;
	
	// PRINTING LINES
	printLine(maxLength, '-', firstLine, firstLine.length());
	printLine(maxLength, ' ', "  ", 2);
	printLine(maxLength, ' ', attack, attackLength);
	printLine(maxLength, ' ', "  ", 2);
	printLine(maxLength, '-', lastLine, lastLine.length());
	std::cout << std::endl;
}

void ClapTrap::printHurt(std::string protag, std::string points)
{
	// CREATING LINES
	std::string firstLine = " " + toUpper(protag) + " takes damages ! ";
	std::string lastLine = " - " + points + " POINTS   (ಥ﹏ಥ) ";
	int maxLength = 52;
	printLine(maxLength, '-', firstLine, firstLine.length());
	printLine(maxLength, ' ', " ", 1);
	printLine(maxLength, ' ', lastLine, 22);
	printLine(maxLength, ' ', " ", 1);
	printLine(maxLength, '-', "-", 1);
	std::cout << std::endl;
}

void ClapTrap::printDead(std::string name)
{
	name = ClapTrap::toUpper(name);
	unsigned long to_add = (57 - name.length()) / 2;
	to_add += name.length() + 1;
	while (name.length() < to_add)
		name = name.insert(0, " ");
	std::cout << name << std::endl;
	std::cout << "                    |----- died. ----|" << std::endl;
	std::cout << "                    |       __       |" << std::endl;
	std::cout << "                    |      |  |      |" << std::endl;
	std::cout << "                    |   ___|  |___   |" << std::endl;
	std::cout << "                    |  [___    ___]  |" << std::endl;
	std::cout << "                    |      |  |      |" << std::endl;
	std::cout << "                    |      |  |      |" << std::endl;
	std::cout << "                    |      |  |      |" << std::endl;
	std::cout << "                    |      |__|      |" << std::endl;
	std::cout << "                    |                |" << std::endl;
	std::cout << "                    |---- PRESS F ---|" << std::endl << std::endl;

}

// CONSTRUCTEURS

ClapTrap::ClapTrap() : _hitPoints(100), _maxHitPoints(100), \
	_energyPoints(100), _maxEnergyPoints(100), _level(1), _name("Bob"), \
	_meleeAttackDamage(30), _rangedAttackDamage(20), _armorDamageReduction(5) {
		std::cout << "\e[2m[ ClapTrap Bob created ]\e[0m" << std::endl << std::endl;
		srand(time(NULL));
	}

ClapTrap::ClapTrap(std::string name) :_hitPoints(100), _maxHitPoints(100), \
	_energyPoints(100), _maxEnergyPoints(100), _level(1), _name(name), \
	_meleeAttackDamage(30), _rangedAttackDamage(20), _armorDamageReduction(5) {
		std::cout << "\e[2m[ " << name << " ClapTrap created ]\e[0m" << std::endl << std::endl;
		srand(time(NULL));
	}

ClapTrap::ClapTrap(ClapTrap const & src) {
	std::cout << "\e[2m[ ClapTrap copy constructor called ]\e[0m" << std::endl << std::endl;
	*this = src;
	return ;
}

ClapTrap::~ClapTrap() {
	std::cout << "\e[2m[ " << this->_name << " has been DESTROYED ]\e[0m" << std::endl << std::endl;
}

ClapTrap &		ClapTrap::operator=(ClapTrap const & src)
{
	std::cout << "\e[2m[ Assignation operator called ]\e[0m" << std::endl << std::endl;
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
	std::ostringstream points;
    points << this->_rangedAttackDamage;
	printAttack(this->_name, "RANGED ATTACK", \
		"(　･ω･)っ≡つ     - Yeehaaw !", \
		28, points.str(), target);
}

void ClapTrap::meleeAttack(std::string const & target) {
	std::ostringstream points;
    points << this->_meleeAttackDamage;
	printAttack(this->_name, "MELEE ATTACK", \
		"o(・_・)9     - Come get a taste of my fists !", \
		46, points.str(), target);
}

void ClapTrap::takeDamage(unsigned int amount) {
	amount -= this->_armorDamageReduction;
	if (amount > this->_hitPoints)
		this->_hitPoints = 0;
	else
		this->_hitPoints -= amount;
	std::ostringstream points;
    points << amount;
	printHurt(this->_name, points.str());
	if (this->_hitPoints <= 0)
		printDead(this->_name);
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
