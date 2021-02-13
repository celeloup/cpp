#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include <string>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

public:
	FragTrap(void);
	FragTrap(std::string name);
	FragTrap(FragTrap const & src);
	~FragTrap();
	FragTrap	& operator=(FragTrap const & src);
	
	void vaulthunter_dot_exe(std::string const & target);

	void magicAttack(std::string const & target);
	void swagAttack(std::string const & target);
	void kamehaAttack(std::string const & target);
	void flipTableAttack(std::string const & target);
	void hugAttack(std::string const & target);

private:
	void initialisation();

};

#endif