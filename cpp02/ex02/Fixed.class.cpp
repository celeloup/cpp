#include "Fixed.class.hpp"

const int    Fixed::_nbBit = 8;

Fixed::Fixed() : _fixed(0) {}

Fixed::Fixed(int integer) {
	this->_fixed = integer << this->_nbBit;
}

Fixed::Fixed(float floater) {
	this->_fixed = (int)(roundf(floater * (1 << this->_nbBit)));
}

Fixed::Fixed(Fixed const & src) {
	*this = src;
	return ;
}

Fixed::~Fixed() {}


// OPERATEUR ASSIGNATION
Fixed &		Fixed::operator=(Fixed const & value) {
	this->_fixed = value.getRawBits();
	return *this;
}

// OPERATEURS COMPARAISON
bool		Fixed::operator>(Fixed const & fix)
{
	return (this->_fixed > fix.getRawBits());
}
bool		Fixed::operator<(Fixed const & fix)
{
	return (this->_fixed < fix.getRawBits());
}
bool		Fixed::operator>=(Fixed const & fix)
{
	return (this->_fixed >= fix.getRawBits());
}
bool		Fixed::operator<=(Fixed const & fix)
{
	return (this->_fixed <= fix.getRawBits());
}
bool		Fixed::operator==(Fixed const & fix)
{
	return (this->_fixed == fix.getRawBits());
}
bool		Fixed::operator!=(Fixed const & fix)
{
	return (this->_fixed != fix.getRawBits());
}

// OPERATEURS ARITHMETIQUES
Fixed Fixed::operator+(Fixed const & fix) const {
	Fixed ret;
    ret.setRawBits(this->_fixed + fix.getRawBits());
    return (ret);
}

Fixed Fixed::operator-(Fixed const & fix) const {
	Fixed ret;
    ret.setRawBits(this->_fixed - fix.getRawBits());
    return (ret);
}

Fixed Fixed::operator*(Fixed const & fix) const {
	Fixed ret;
    ret.setRawBits((this->_fixed * fix.getRawBits()) >> this->_nbBit);
    return (ret);
}

Fixed Fixed::operator/(Fixed const & fix) const {
	Fixed ret;
    ret.setRawBits((this->_fixed << this->_nbBit) / fix.getRawBits());
    return (ret);
}

Fixed & Fixed::operator++(void) {	// pre-inc
	this->_fixed++;
	return (*this);
}

Fixed Fixed::operator++(int) {		// post-inc
	Fixed ret(*this);
	this->_fixed++;
	return (ret);
}
Fixed & Fixed::operator--(void) {	// pre-dec
	this->_fixed--;
	return (*this);
}
Fixed Fixed::operator--(int) {		// post-dec
	Fixed ret(*this);
	this->_fixed--;
	return (ret);
}

// FONCTIONS MEMBRES

int		Fixed::getRawBits(void) const {
	return this->_fixed;
}

void	Fixed::setRawBits(int const raw) { 
	this->_fixed = raw;
}

int Fixed::toInt(void) const {
    return ((int)(this->_fixed >> this->_nbBit));
}

float Fixed::toFloat(void) const {
    return ((float)this->_fixed / (float)(1 << this->_nbBit));
}

// FONCTIONS NON-MEMBRES

std::ostream &operator<<(std::ostream &outStream, const Fixed &fixedValue) {
    outStream << fixedValue.toFloat();
    return (outStream);
}

// Fixed &min(Fixed &a, Fixed &b) {
// 	if (a < b)
// 		return (a);
// 	else
// 		return (b);
// }
// Fixed &max(Fixed &a, Fixed &b) {
// 	if (a > b)
// 		return (a);
// 	else
// 		return (b);
// }

// Fixed const &min(Fixed const &a, Fixed const &b) {
// 	if (&a < &b)
// 		return (a);
// 	else
// 		return (b);
// }
// Fixed const &max(Fixed const &a, Fixed const &b) {
// 	if (&a > &b)
// 		return (a);
// 	else
// 		return (b);
// }

