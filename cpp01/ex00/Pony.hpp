#ifndef PONY_H
# define PONY_H

#include <string>

class Pony
{

public:
	Pony(void);
	Pony(std::string name, std::string meal);
	~Pony(void);
	std::string		get_name();
	std::string		get_meal();
	void			talk(void);
private:
	std::string name;
	std::string favorite_meal;
};

#endif