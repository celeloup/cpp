/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celeloup <celeloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 11:11:09 by celeloup          #+#    #+#             */
/*   Updated: 2021/01/23 10:22:04 by celeloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

#include <sstream>
#include <string>
#include <stdlib.h>


// CONSTRUCTEURS

void	FragTrap::initialisation()
{
	this->_hitPoints = 100;
	this->_maxHitPoints = 100;
	this->_energyPoints = 100;
	this->_maxEnergyPoints = 100;
	this->_level = 1;
	this->_meleeAttackDamage = 30;
	this->_rangedAttackDamage = 20;
	this->_armorDamageReduction = 5;
}

FragTrap::FragTrap() : ClapTrap() {
	initialisation();
	std::cout << "\e[2m[ FR4G-TP " << this->_name << " summoned ]\e[0m" << std::endl << std::endl;
	srand(time(NULL));
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	initialisation();
	std::cout << "\e[2m[ FR4G-TP " << name << " summoned ]\e[0m" << std::endl << std::endl;
	srand(time(NULL));
}

FragTrap::FragTrap(FragTrap const & src) : ClapTrap(src) {}

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

FragTrap::~FragTrap() {
	std::cout << "\e[2m[ FR4G-TP " << this->_name << " dismissed ]\e[0m" << std::endl;
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
	std::cout << " ੭•̀ω•́)੭̸*✩⁺˚     - Sparkles all over you !" << std::endl;
	std::cout << "Causing 25 points of damage." << std::endl << std::endl;
}

void FragTrap::kamehaAttack(std::string const & target) {
	std::cout << this->_name << " used KAMEHAMEHA ATTACK on " << target << std::endl;
	std::cout << " ༼つಠ益ಠ༽つ ─=≡ΣO))     - かめはめ 波 は !" << std::endl;
	std::cout << "Causing 105 points of damage." << std::endl << std::endl;
}

void FragTrap::flipTableAttack(std::string const & target) {
	std::cout << this->_name << " used FLIP TABLE ATTACK on " << target << std::endl;
	std::cout << " (ﾉಠдಠ)ﾉ︵┻━┻     - Tables have turned !" << std::endl;
	std::cout << "Causing 40 points of damage." << std::endl << std::endl;
}

void FragTrap::swagAttack(std::string const & target) {
	std::cout << this->_name << " used SWAG ATTACK on " << target << std::endl;
	std::cout << " (つ▀¯▀)つ     - You can't handle my swag." << std::endl;
	std::cout << "Causing 65 points of damage." << std::endl << std::endl;
}

void FragTrap::hugAttack(std::string const & target) {
	std::cout << this->_name << " used HUG ATTACK on " << target << std::endl;
	std::cout << " (づ￣ ³￣)づ     - Come here baby." << std::endl;
	std::cout << "Causing 10 points of damage." << std::endl << std::endl;
}