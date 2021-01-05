#include "Pony.hpp"
#include <iostream>

Pony::Pony() {}

Pony::Pony(std::string name, std::string meal) \
	: name(name), favorite_meal(meal) {}

Pony::~Pony() {
	std::cout << "Pony " << this->get_name() << " got destroyed." << std::endl;
}

std::string Pony::get_name(void)	{ return (this->name); }
std::string Pony::get_meal(void)	{ return (this->favorite_meal); }

void Pony::talk(void)
{
	std::cout << "   Hello I'm ";
	std::cout << this->get_name();
	std::cout << " and i love ";
	std::cout << this->get_meal();
	std::cout << " ! " << std::endl;
}