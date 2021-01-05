#include "Human.hpp"

std::string Human::identify(void) const
{
	return (this->brain.identify());
}

Brain const &Human::getBrain() const
{
	return this->brain;
}