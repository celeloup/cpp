#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent() {}
ZombieEvent::~ZombieEvent() {}

void ZombieEvent::setZombieType(std::string type)
{
	this->type = type;
}

Zombie* ZombieEvent::newZombie(std::string name)
{
	Zombie *zomb;
	if (this->type != "")
		zomb = new Zombie(name, this->type);
	else
		zomb = new Zombie(name, "normal");
	return (zomb);
}

Zombie* ZombieEvent::randomChump(void)
{
	Zombie *zomb;
	srand (time(NULL));
	int index = rand() % 9;
	std::string names[10] = {"Tommy", "Jack", "Daniel", "Santa", "Barbara", "Chloe", "Rachel", "Max", "Robert", "Henry" };
	zomb = new Zombie(names[index], this->type);
	zomb->announce();
	return (zomb);
}