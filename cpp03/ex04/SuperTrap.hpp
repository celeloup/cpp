#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

#include "FragTrap.hpp"
#include "NinjaTrap.hpp"
#include <string>

class SuperTrap : public FragTrap, public NinjaTrap{

public:
	SuperTrap(void);
	SuperTrap(std::string name);
	SuperTrap(SuperTrap const & src);
	~SuperTrap();
	SuperTrap	& operator=(SuperTrap const & src);
	
	void rangedAttack(std::string const & target);
	void meleeAttack(std::string const & target);

private:
	void initialisation();
};

#endif