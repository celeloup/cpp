/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celeloup <celeloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 11:10:50 by celeloup          #+#    #+#             */
/*   Updated: 2021/01/23 10:28:36 by celeloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

#include <sstream>
#include <string>
#include <stdlib.h>

void	ScavTrap::initialisation()
{
	this->_hitPoints = 100;
	this->_maxHitPoints = 100;
	this->_energyPoints = 50;
	this->_maxEnergyPoints = 50;
	this->_level = 1;
	this->_meleeAttackDamage = 20;
	this->_rangedAttackDamage = 15;
	this->_armorDamageReduction = 3;
}

// CONSTRUCTEURS

ScavTrap::ScavTrap() : ClapTrap() {
	initialisation();
	std::cout << "\e[2m[ Wild SC4V-TP " << this->_name << " appeared ! ]\e[0m" << std::endl << std::endl;
	srand(time(NULL));
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	initialisation();
	std::cout << "\e[2m[ Wild SC4V-TP " << name << " appeared ! ]\e[0m" << std::endl << std::endl;
	srand(time(NULL));
}

ScavTrap::ScavTrap(ScavTrap const & src) : ClapTrap(src) {}

ScavTrap::~ScavTrap() {
	std::cout << "\e[2m[ SC4V-TP " << this->_name << " is going back to where it came from ... ]\e[0m" << std::endl;
}

ScavTrap &		ScavTrap::operator=(ScavTrap const & src)
{
	std::cout << "\e[2m[ SC4V-TP assigned ]\e[0m" << std::endl << std::endl;
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

void ScavTrap::danceChallenge(std::string const & target) {
	std::cout << this->_name << " challenges " << target << " to a DANCE BATTLE !" << std::endl;
	std::cout << "  ಠ_ಠ     - I want to see your best move !" << std::endl << std::endl;
}

void ScavTrap::singingChallenge(std::string const & target) {
	std::cout << this->_name << " challenges " << target << " to a SINGING CONTEST !" << std::endl;
	std::cout << "  ♪～(￣ε￣)     - I BelIEve i CAn fLYyyYY !" << std::endl << std::endl;
}

void ScavTrap::flipChallenge(std::string const & target) {
	std::cout << this->_name << " challenges " << target << " to a FLIP CHALLENGE !" << std::endl;
	std::cout << "  (ﾉಠдಠ)ﾉ︵     - Do a back flip OR DIE !" << std::endl << std::endl;
}

void ScavTrap::riddleChallenge(std::string const & target) {
	std::cout << this->_name << " challenges " << target << " to a RIDDLE!" << std::endl;
	std::cout << "  (╭ರ_⊙)     - What has legs, but doesn’t walk?" << std::endl << std::endl;
}

void ScavTrap::shifumiChallenge(std::string const & target) {
	std::cout << this->_name << " challenges " << target << " to a SHIFUMI !" << std::endl;
	std::cout << "  ಠ▃ಠ     - Ready ? Rock, paper, cisors, shoot !" << std::endl << std::endl;
}