#include "ZombieEvent.hpp"

int main(void)
{
	Zombie *zomb;
	ZombieEvent zombiland;

	zomb = new Zombie("Tom", "theOriginalOne");
	zomb->announce();
	delete zomb;

	zomb = zombiland.newZombie("Leo");
	zomb->announce();
	delete zomb;

	zombiland.setZombieType("runner");

	zomb = zombiland.newZombie("Robbie");
	zomb->announce();
	delete zomb;

	zomb = zombiland.randomChump();
	delete zomb;
	
	return (0);
}