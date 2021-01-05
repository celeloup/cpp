#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include <string>

class FragTrap {

public:
	FragTrap(void);
	FragTrap(std::string name);
	FragTrap(FragTrap const & src);
	~FragTrap();
	FragTrap	& operator=(FragTrap const & src);

	void rangedAttack(std::string const & target);
	void meleeAttack(std::string const & target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void vaulthunter_dot_exe(std::string const & target);

	void magicAttack(std::string const & target);
	void swagAttack(std::string const & target);
	void kamehaAttack(std::string const & target);
	void flipTableAttack(std::string const & target);
	void hugAttack(std::string const & target);

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
};

#endif