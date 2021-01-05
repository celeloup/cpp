#include "ZombieHorde.hpp"
#include <limits.h>
#include <iostream>

ZombieHorde::ZombieHorde(int n)
{
	if (n < 1 || n > INT_MAX)
	{
		std::cout << "Invalid number of zombies. Number set to 1." << std::endl;
		n = 1;
	}
	this->zombies = new Zombie[n];
	this->nb_zomb = n;
	srand (time(NULL));
	int index;
	int index_type;
	std::string names[20] = {"Tommy", "Jack", "Daniel", "Santa", "Barbara", "Chloe", "Rachel", "Max", "Robert", "Henry", \
							"Cathy", "Roger", "Romain", "Olivia", "Tony", "Alice", "Elizabeth", "Oscar", "Jean", "Babar"};
	std::string types[6] = {"normal", "runner", "scary", "stinky", "slow", "fast"};
	for (int i = 0; i < n; i++)
	{
		index = rand() % 20;
		index_type = rand() % 6;
		this->zombies[i].setName(names[index]);
		this->zombies[i].setType(types[index_type]);
	}
}

ZombieHorde::~ZombieHorde()
{
	delete[] this->zombies;
}

void	ZombieHorde::announce()
{
	for(int i = 0; i < this->nb_zomb; i++)
	{
		this->zombies[i].announce();
	}
}