#ifndef FIXED_CLASS_H
# define FIXED_CLASS_H

class Fixed {

public:
	Fixed(void);
	Fixed(Fixed const & src);
	~Fixed(void);

	Fixed &		operator=(Fixed const & value);

	int getRawBits(void) const;
	void setRawBits(int const raw); 

private:
	int _fixed;
	static const int _nbBit;

};

#endif