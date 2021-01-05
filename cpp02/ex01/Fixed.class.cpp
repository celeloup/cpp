#include "Fixed.class.hpp"

const int    Fixed::_nbBit = 8;

Fixed::Fixed() : _fixed(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int integer)
{
	std::cout << "Integer constructor called" << std::endl;
	this->_fixed = integer << this->_nbBit;
}

Fixed::Fixed(float floater)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixed = (int)(roundf(floater * (1 << this->_nbBit)));
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

int Fixed::toInt(void) const
{
    return ((int)(this->_fixed >> this->_nbBit));
}

float Fixed::toFloat(void) const
{
    return ((float)this->_fixed / (float)(1 << this->_nbBit));
}


std::ostream &operator<<(std::ostream &outStream, const Fixed &fixedValue)
{
    outStream << fixedValue.toFloat();
    return (outStream);
}
