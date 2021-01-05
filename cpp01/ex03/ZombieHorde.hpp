#ifndef ZOMBIEHORD_H
# define ZOMBIEHORD_H

#include "Zombie.hpp"
#include <stdlib.h>

class ZombieHorde
{
public:
	ZombieHorde(int n);
	~ZombieHorde();
	void announce(void);
private:
	int nb_zomb;
	Zombie *zombies;
};

#endif