/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celeloup <celeloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 11:11:04 by celeloup          #+#    #+#             */
/*   Updated: 2021/01/06 14:59:10 by celeloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <string>

class ScavTrap {

public:
	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(ScavTrap const & src);
	~ScavTrap();
	ScavTrap	& operator=(ScavTrap const & src);

	void rangedAttack(std::string const & target);
	void meleeAttack(std::string const & target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void challengeNewcomer(std::string const & target);

	void danceChallenge(std::string const & target);
	void singingChallenge(std::string const & target);
	void flipChallenge(std::string const & target);
	void riddleChallenge(std::string const & target);
	void shifumiChallenge(std::string const & target);

private:
	unsigned int	_hitPoints;
	unsigned int	_maxHitPoints;
	unsigned int	_energyPoints;
	unsigned int	_maxEnergyPoints;
	unsigned int	_level;
	std::string		_name;
	unsigned int	_meleeAttackDamage;
	unsigned int	_rangedAttackDamage;
	unsigned int	_armorDamageReduction;
	std::string		toUpper(std::string str);
	void	printLine(int maxLength, char fill, std::string str, int strLength);
	void	printAttack(std::string attacker, std::string attackName, \
		std::string attack, unsigned long attackLength, std::string points, std::string target);
	void printHurt(std::string protag, std::string points);
	void printDead(std::string name);
	void printChallenge(std::string challenger, std::string challengeName, \
		std::string challenge, unsigned long challengeLength, std::string target);
};

#endif