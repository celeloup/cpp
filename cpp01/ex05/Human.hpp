#ifndef HUMAN_H
# define HUMAN_H
#include <string>
#include "Brain.hpp"
class Human
{
	public:
	std::string identify(void) const;
	Brain const &getBrain() const;

	private:
	Brain const brain;
};

#endif