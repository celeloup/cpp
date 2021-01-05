#include "Fixed.class.hpp"
#include <iostream>

const int    Fixed::_nbBit = 8;

Fixed::Fixed() : _fixed(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed &		Fixed::operator=(Fixed const & value)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_fixed = value.getRawBits();
	return *this;
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixed;
}

void	Fixed::setRawBits(int const raw) 
{ 
	this->_fixed = raw;
}