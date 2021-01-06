/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celeloup <celeloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 11:10:50 by celeloup          #+#    #+#             */
/*   Updated: 2021/01/06 14:59:21 by celeloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

#include <sstream>
#include <string>
#include <stdlib.h>


// UTILS

std::string ScavTrap::toUpper(std::string str)
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

void	ScavTrap::printLine(int maxLength, char fill, std::string str, int strLength)
{
	std::string color = "  |";
	std::string end = "|";

	int fillLength = (maxLength - strLength) / 2;
	std::string fillStr(fillLength, fill);
	if ((maxLength - strLength) % 2 == 0)
		std::cout << color << fillStr << str << fillStr << end << std::endl;
	else
		std::cout << color << fillStr << str << fillStr << fill << end << std::endl;
}

void	ScavTrap::printAttack(std::string attacker, std::string attackName, \
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

void ScavTrap::printHurt(std::string protag, std::string points)
{
	// CREATING LINES
	std::string firstLine = " " + toUpper(protag) + " said OUCH ! ";
	std::string lastLine = " - " + points + " POINTS   (ಥ﹏ಥ) ";
	int maxLength = 52;
	printLine(maxLength, '-', firstLine, firstLine.length());
	printLine(maxLength, ' ', " ", 1);
	printLine(maxLength, ' ', lastLine, 22);
	printLine(maxLength, ' ', " ", 1);
	printLine(maxLength, '-', "-", 1);
	std::cout << std::endl;
}

void ScavTrap::printDead(std::string name)
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

ScavTrap::ScavTrap() : _hitPoints(100), _maxHitPoints(100), \
	_energyPoints(50), _maxEnergyPoints(50), _level(1), _name("Robert"), \
	_meleeAttackDamage(20), _rangedAttackDamage(15), _armorDamageReduction(3) {
		std::cout << "\e[2m[ Wild ROBERT appeared ! ]\e[0m" << std::endl << std::endl;
		srand(time(NULL));
	}

ScavTrap::ScavTrap(std::string name) :_hitPoints(100), _maxHitPoints(100), \
	_energyPoints(50), _maxEnergyPoints(50), _level(1), _name(name), \
	_meleeAttackDamage(20), _rangedAttackDamage(15), _armorDamageReduction(3) {
		std::cout << "\e[2m[ Wild " << toUpper(name) << " appeared ! ]\e[0m" << std::endl << std::endl;
		srand(time(NULL));
	}

ScavTrap::ScavTrap(ScavTrap const & src) {
	std::cout << "\e[2m[ Copy constructor called ]\e[0m" << std::endl << std::endl;
	*this = src;
	return ;
}

ScavTrap::~ScavTrap() {
	std::cout << "\e[2m[ " << this->_name << " is going back to where it came from ... (don't ask me where that is, i don't know either) ]\e[0m" << std::endl << std::endl;
}

ScavTrap &		ScavTrap::operator=(ScavTrap const & src)
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

void ScavTrap::rangedAttack(std::string const & target) {
	std::ostringstream points;
    points << this->_rangedAttackDamage;
	printAttack(this->_name, "RANGED ATTACK", \
		"ಠoಠ     - No matter the way, I'll CRUSH you !", \
		45, points.str(), target);
}

void ScavTrap::meleeAttack(std::string const & target) {
	std::ostringstream points;
    points << this->_meleeAttackDamage;
	printAttack(this->_name, "MELEE ATTACK", \
		"ヽ(`Д´)ﾉ     - I WILL DEFEAT YOU !", \
		34, points.str(), target);
}

void ScavTrap::takeDamage(unsigned int amount) {
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

void ScavTrap::beRepaired(unsigned int amount) {
	if (this->_hitPoints <= 0)
	{
		std::cout << "\e[2m[ " << this->_name << " has left this world. No reparations will fix that ... ]\e[0m" << std::endl << std::endl;
		return ;
	}	
	std::cout << "\e[2m[ " << this->_name << " is gluing its pieces back with SUPER GLUE ! It's SUPER EFFECTIVE ! ";
	if (this->_hitPoints == _maxHitPoints)
		std::cout << "But everything was already in place !]\e[0m" << std::endl << std::endl;
	else if (this->_hitPoints + amount >= this->_maxHitPoints)
		this->_hitPoints = this->_maxHitPoints;
	else
		this->_hitPoints += amount;
	std::cout << "Back to " << this->_hitPoints << " PV (+" << amount << ") ]\e[0m" << std::endl << std::endl;
}

void ScavTrap::challengeNewcomer(std::string const & target) {
	if (this->_energyPoints < 25)
		std::cout << "\e[2m[ " << this->_name << " is to tired to challenge anyone. Free entry for everybody ! ]\e[0m" << std::endl << std::endl;
	else
	{
		this->_energyPoints -= 25;
		
		int index = rand() % 5;
		switch (index)
		{
		case 1:
			riddleChallenge(target);
			break;
		case 2:
			singingChallenge(target);
			break;
		case 3:
			danceChallenge(target);
			break;
		case 4:
			flipChallenge(target);
			break;
		default:
			shifumiChallenge(target);
			break;
		}
	}
}

void ScavTrap::printChallenge(std::string challenger, std::string challengeName, \
	std::string challenge, unsigned long challengeLength, std::string target)
{
	// CREATING LINES
	std::string firstLine = " " + toUpper(challenger) + " challenges " + toUpper(target) + " to a " + challengeName + " ! ";
	
	// DETERMINATING MAX LENGTH
	unsigned long maxLength = 52;
	if (firstLine.length() > maxLength)
		maxLength = firstLine.length();
	if ( challengeLength > maxLength)
		maxLength = challengeLength;
	
	// PRINTING LINES
	printLine(maxLength, '-', firstLine, firstLine.length());
	printLine(maxLength, ' ', "  ", 2);
	printLine(maxLength, ' ', challenge, challengeLength);
	printLine(maxLength, ' ', "  ", 2);
	printLine(maxLength, '-', "-", 1);
	std::cout << std::endl;
}

void ScavTrap::danceChallenge(std::string const & target) {

	printChallenge(this->_name, "DANCE BATTLE", \
		"ಠ_ಠ     - I want to see your best move !", \
		40, target);
}

void ScavTrap::singingChallenge(std::string const & target) {

	printChallenge(this->_name, "SINGING CONTEST", \
		"♪～(￣ε￣)     - I BelIEve i CAn fLYyyYY !", \
		42, target);
}

void ScavTrap::flipChallenge(std::string const & target) {
	printChallenge(this->_name, "FLIP CHALLENGE", \
		"(ﾉಠдಠ)ﾉ︵     - Do a back flip OR DIE !", \
		39, target);
}

void ScavTrap::riddleChallenge(std::string const & target) {
	printChallenge(this->_name, "RIDDLE", \
		"(╭ರ_⊙)     - What has legs, but doesn’t walk?", \
		45, target);
}

void ScavTrap::shifumiChallenge(std::string const & target) {
	printChallenge(this->_name, "SHIFUMI", \
		"ಠ▃ಠ     - Ready ? Rock, paper, cisors, shoot !", \
		46, target);
}