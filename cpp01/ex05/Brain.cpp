#include "Brain.hpp"
#include <iostream>
#include <sstream>

Brain::Brain()
{
	this->memories = "My dad used to make delicious churros on Christmas";
}

Brain::~Brain() {}

std::string  Brain::identify() const
{
	std::ostringstream address;
	address << this;
	return (address.str());
}