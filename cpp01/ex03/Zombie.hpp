#ifndef ZOMBIE_H
# define PONY_H

#include <string>

class Zombie
{
public:
	Zombie();
	Zombie(std::string name, std::string type);
	~Zombie();
	void	announce(void);
	void	setName(std::string name);
	void	setType(std::string type);
private:
	std::string name;
	std::string type;
};

#endif