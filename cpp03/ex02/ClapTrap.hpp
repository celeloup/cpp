#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>

class ClapTrap {

public:
	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const & src);
	~ClapTrap();
	ClapTrap	& operator=(ClapTrap const & src);

	void rangedAttack(std::string const & target);
	void meleeAttack(std::string const & target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

protected:
	unsigned int	_hitPoints;
	unsigned int	_maxHitPoints;
	unsigned int	_energyPoints;
	unsigned int	_maxEnergyPoints;
	unsigned int	_level;
	std::string		_name;
	unsigned int	_meleeAttackDamage;
	unsigned int	_rangedAttackDamage;
	unsigned int	_armorDamageReduction;
	
	//UTILS
	std::string		toUpper(std::string str);
	void	printLine(int maxLength, char fill, std::string str, int strLength);
	void	printAttack(std::string attacker, std::string attackName, \
		std::string attack, unsigned long attackLength, std::string points, std::string target);
	void printHurt(std::string protag, std::string points);
	void printDead(std::string name);
};

#endif