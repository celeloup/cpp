#include "ZombieHorde.hpp"
#include <iostream>

int main(void)
{
	std::cout << "  \e[2mOh no ! A small horde of 2 zombies is coming !\e[0m" << std::endl;
	ZombieHorde small_horde(2);
	small_horde.announce();

	std::cout << std::endl << "  \e[2mAaah ! A bigger horde of 10 zombies is attacking us now !\e[0m" << std::endl;
	ZombieHorde horde(10);
	horde.announce();

	std::cout << std::endl << "  \e[2mJust when i thought we were done ? ANOTHER horde of -5 zombies !" << std::endl << "  Wait. -5 ? How can it be ?\e[0m" << std::endl;
	ZombieHorde bad_horde(-5);
	bad_horde.announce();

	std::cout << std::endl << "  \e[2m[sigh of relief] It was alone. All the zombies are dead now !" << std::endl << "    (check valgrind if you don't believe me)\e[0m" << std::endl;
	return (0);
}