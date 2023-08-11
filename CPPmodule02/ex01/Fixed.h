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
	Fixed(const int value);
	Fixed(const float value);
	Fixed &operator=(const Fixed &fixed);
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat( void ) const;
	int toInt( void ) const;
};
#endif //C__CIRCLE_FIXED_H
