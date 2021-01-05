#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() {}
Zombie::Zombie(std::string name, std::string type) : name(name), type(type) {}

Zombie::~Zombie() {}

void	Zombie::announce(void)
{
	std::cout << "<" << this->name << " (" \
		<< this->type << ")> Braaaaaiiiiinnnnsss ..." << std::endl;
}