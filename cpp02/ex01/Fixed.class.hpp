#ifndef FIXED_CLASS_H
# define FIXED_CLASS_H

#include <cmath>
#include <iostream>

class Fixed {

public:
	Fixed(void);
	Fixed(int integer);
	Fixed(float floater);
	Fixed(Fixed const & src);
	~Fixed(void);

	Fixed &		operator=(Fixed const & value);

	int getRawBits(void) const;
	void setRawBits(int const raw);

	float toFloat(void) const;
	int toInt(void) const;

private:
	int _fixed;
	static const int _nbBit;

};

std::ostream &operator<<(std::ostream &outStream, const Fixed &fixedValue);

#endif