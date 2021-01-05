#ifndef ZOMBIEEVENT_H
# define ZOMBIEEVENT_H

#include "Zombie.hpp"
#include <string>
#include <stdlib.h>

class ZombieEvent
{
public:
	ZombieEvent();
	~ZombieEvent();
	void setZombieType(std::string type);
	Zombie *newZombie (std::string name);
	Zombie	*randomChump(void);
private:
	std::string type;
};

#endif