/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celeloup <celeloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 11:11:09 by celeloup          #+#    #+#             */
/*   Updated: 2021/01/06 15:57:51 by celeloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

#include <sstream>
#include <string>
#include <stdlib.h>


// CONSTRUCTEURS

FragTrap::FragTrap() : ClapTrap() {
		std::cout << "\e[2m[ Albert has been SUMMONED ]\e[0m" << std::endl << std::endl;
		srand(time(NULL));
	}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
		std::cout << "\e[2m[ " << name << " has been SUMMONED ]\e[0m" << std::endl << std::endl;
		srand(time(NULL));
	}

// FragTrap::FragTrap(FragTrap const & src) : ClapTrap(src) {
// 	std::cout << "\e[2m[ Copy constructor called ]\e[0m" << std::endl << std::endl;
// 	*this = src;
// 	return ;
// }

// FragTrap &		FragTrap::operator=(FragTrap const & src) : 
// {
// 	std::cout << "\e[2m[ Assignation operator called ]\e[0m" << std::endl << std::endl;
// 	if (this == &src)
// 		return (*this);
// 	this->_hitPoints = src._hitPoints;
// 	this->_maxHitPoints = src._maxHitPoints;
// 	this->_energyPoints = src._energyPoints;
// 	this->_maxEnergyPoints = src._maxEnergyPoints;
// 	this->_level = src._level;
// 	this->_name = src._name;
// 	this->_meleeAttackDamage = src._meleeAttackDamage;
// 	this->_rangedAttackDamage = src._rangedAttackDamage;
// 	this->_armorDamageReduction = src._armorDamageReduction;
// 	return (*this);
// }

FragTrap::~FragTrap() {
	std::cout << "\e[2m[ " << this->_name << " has been DESTROYED ]\e[0m" << std::endl << std::endl;
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