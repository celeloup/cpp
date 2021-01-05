#include <iostream>
#include "Fixed.class.hpp"

int main(void) {
	// TESTS SUJET
	std::cout << "  ** Subject tests **" << std::endl;
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	//std::cout << max(a, b) << std::endl;
	
	// TESTS PERSO
	std::cout << "  ** Personnal tests **" << std::endl;
	std::cout << --a << std::endl;
	std::cout << a << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;
	
	std::cout << "  ** Comparaison tests **" << std::endl;
	Fixed c(25);
	Fixed d(2.6f);
	std::cout << (c == d) << std::endl;
	std::cout << (c != d) << std::endl;
	std::cout << (c < d) << std::endl;
	std::cout << (c <= d) << std::endl;
	std::cout << (c > d) << std::endl;
	std::cout << (c >= d) << std::endl;
	Fixed e(25);
	std::cout << (c == e) << std::endl;
	std::cout << (c >= e) << std::endl;
	std::cout << (c <= e) << std::endl;

	std::cout << "  ** Arithmetic tests **" << std::endl;
	std::cout << a + b << std::endl;
	std::cout << c - b << std::endl;
	std::cout << d * b << std::endl;
	std::cout << c / b << std::endl;
	return 0;
}