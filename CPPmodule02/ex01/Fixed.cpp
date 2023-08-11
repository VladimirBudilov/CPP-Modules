#include <cmath>
#include "Fixed.h"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_value = 0;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	_value = value << _fractional_bits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(value * (1 << _fractional_bits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

void Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}


Fixed &Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (&fixed != this)
		_value = fixed._value;
	return *this;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}


std::ostream &operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return o;
}

float Fixed::toFloat(void) const
{
	return (float) _value / (1 << _fractional_bits);
}

int Fixed::toInt(void) const
{
	return _value >> _fractional_bits;
}
