#ifndef C__CIRCLE_FIXED_H
#define C__CIRCLE_FIXED_H

#include <iostream>

class Fixed {
private:
	int _value;
	static const int _fractional_bits = 8;
public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &fixed);
	Fixed &operator=(const Fixed &fixed);
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif //C__CIRCLE_FIXED_H
