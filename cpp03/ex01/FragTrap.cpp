#include "FragTrap.hpp"
#include <iostream>

#include <sstream>
#include <string>
#include <stdlib.h>


// UTILS

std::string toUpper(std::string str)
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

void	printLine(int maxLength, char fill, std::string str, int strLength)
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

void	printAttack(std::string attacker, std::string attackName, \
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

void printHurt(std::string protag, std::string points)
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

void printDead(std::string name)
{
	name = toUpper(name);
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

FragTrap::FragTrap() : _hitPoints(100), _maxHitPoints(100), \
	_energyPoints(100), _maxEnergyPoints(100), _level(1), _name("Albert"), \
	_meleeAttackDamage(30), _rangedAttackDamage(20), _armorDamageReduction(5) {
		std::cout << "\e[2m[ Albert has been SUMMONED ]\e[0m" << std::endl << std::endl;
		srand(time(NULL));
	}

FragTrap::FragTrap(std::string name) :_hitPoints(100), _maxHitPoints(100), \
	_energyPoints(100), _maxEnergyPoints(100), _level(1), _name(name), \
	_meleeAttackDamage(30), _rangedAttackDamage(20), _armorDamageReduction(5) {
		std::cout << "\e[2m[ " << name << " has been SUMMONED ]\e[0m" << std::endl << std::endl;
		srand(time(NULL));
	}

FragTrap::FragTrap(FragTrap const & src) {
	std::cout << "\e[2m[ Copy constructor called ]\e[0m" << std::endl << std::endl;
	*this = src;
	return ;
}

FragTrap::~FragTrap() {
	std::cout << "\e[2m[ " << this->_name << " has been DESTROYED ]\e[0m" << std::endl << std::endl;
}

FragTrap &		FragTrap::operator=(FragTrap const & src)
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

void FragTrap::rangedAttack(std::string const & target) {
	std::ostringstream points;
    points << this->_rangedAttackDamage;
	printAttack(this->_name, "RANGED ATTACK", \
		"(　･ω･)っ≡つ     - Yeehaaw !", \
		28, points.str(), target);
}

void FragTrap::meleeAttack(std::string const & target) {
	std::ostringstream points;
    points << this->_meleeAttackDamage;
	printAttack(this->_name, "MELEE ATTACK", \
		"o(・_・)9     - Come get a taste of my fists !", \
		46, points.str(), target);
}

void FragTrap::takeDamage(unsigned int amount) {
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

void FragTrap::beRepaired(unsigned int amount) {
	if (this->_hitPoints <= 0)
	{
		std::cout << "\e[2m[ " << this->_name << " is dead. It's too late for reparations :'( ! ]\e[0m" << std::endl << std::endl;
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

	printAttack(this->_name, "MAGIC ATTACK", \
		"੭•̀ω•́)੭̸*✩⁺˚     - Sparkles all over you !", \
		40, "25", target);
}

void FragTrap::kamehaAttack(std::string const & target) {

	printAttack(this->_name, "KAMEHAMEHA ATTACK", \
		"༼つಠ益ಠ༽つ ─=≡ΣO))     - かめはめ 波 は !", \
		41, "105", target);
}

void FragTrap::flipTableAttack(std::string const & target) {
	printAttack(this->_name, "FLIP TABLE ATTACK", \
		"(ﾉಠдಠ)ﾉ︵┻━┻     - Tables have turned !", \
		39, "40", target);
}

void FragTrap::swagAttack(std::string const & target) {
	printAttack(this->_name, "SWAG ATTACK", \
		"(つ▀¯▀)つ     - You can't handle my swag.", \
		41, "65", target);
}

void FragTrap::hugAttack(std::string const & target) {
	printAttack(this->_name, "HUG ATTACK", \
		"(づ￣ ³￣)づ     - Come here baby.", \
		34, "10", target);
}