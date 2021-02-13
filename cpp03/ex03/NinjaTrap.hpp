#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>

class NinjaTrap : public ClapTrap{

public:
	NinjaTrap(void);
	NinjaTrap(std::string name);
	NinjaTrap(NinjaTrap const & src);
	~NinjaTrap();
	NinjaTrap	& operator=(NinjaTrap const & src);

	void ninjaShoebox(NinjaTrap &target);
	void ninjaShoebox(ClapTrap &target);
	void ninjaShoebox(FragTrap &target);
	void ninjaShoebox(ScavTrap &target);

private:
	void initialisation();

};

#endif