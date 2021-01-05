#ifndef BRAIN_H
# define BRAIN_H

#include <string>

class Brain 
{
	public:
	Brain();
	~Brain();
	std::string identify() const;

	private:
	std::string memories;
};


#endif