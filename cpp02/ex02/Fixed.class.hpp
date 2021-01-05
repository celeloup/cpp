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

	bool		operator>(Fixed const & fix);
	bool		operator<(Fixed const & fix);
	bool		operator>=(Fixed const & fix);
	bool		operator<=(Fixed const & fix);
	bool		operator==(Fixed const & fix);
	bool		operator!=(Fixed const & fix);

	Fixed operator+(Fixed const & fix) const;
    Fixed operator-(Fixed const & fix) const;
    Fixed operator*(Fixed const & fix) const;
    Fixed operator/(Fixed const & fix) const;

    Fixed & operator++(void);
    Fixed operator++(int);
    Fixed & operator--(void);
    Fixed operator--(int);

	int getRawBits(void) const;
	void setRawBits(int const raw);

	float toFloat(void) const;
	int toInt(void) const;

private:
	int _fixed;
	static const int _nbBit;

};

std::ostream &operator<<(std::ostream &outStream, const Fixed &fixedValue);

// Fixed &min(Fixed &a, Fixed &b);
// Fixed &max(Fixed &a, Fixed &b);

// Fixed const &min(Fixed const &a, Fixed const &b);
// Fixed const &max(Fixed const &a, Fixed const &b);

#endif