#include <cmath>
#include "Fixed.h"

///Constructors and destructor

Fixed::Fixed()
{
	//std::cout << "Default constructor called" << std::endl;
	_value = 0;
}

Fixed::Fixed(const Fixed &fixed)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::Fixed(const int value)
{
	//std::cout << "Int constructor called" << std::endl;
	_value = value << _fractional_bits;
}

Fixed::Fixed(const float value)
{
	//std::cout << "Float constructor called" << std::endl;
	_value = roundf(value * (1 << _fractional_bits));
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

///Getters and setters

void Fixed::setRawBits(const int raw)
{
	//std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

int Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return _value;
}


///Member functions

float Fixed::toFloat(void) const
{
	return (float) _value / (1 << _fractional_bits);
}

int Fixed::toInt(void) const
{
	return _value >> _fractional_bits;
}

///Overloaders

Fixed &Fixed::operator=(const Fixed &fixed)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (&fixed != this)
		_value = fixed._value;
	return *this;
}

std::ostream &operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return o;
}

Fixed Fixed::operator+(const Fixed &fixed) const
{
	return Fixed(toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed &fixed) const
{
	return Fixed(toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed &fixed) const
{
	return Fixed(toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed &fixed) const
{
	if(fixed.toFloat() == 0)
	{
		std::cout << "Dummy, it isn't cool to do division by zero, but i fixed it)" << std::endl;
		return Fixed(0);
	}
	return Fixed(toFloat() / fixed.toFloat());
}

Fixed &Fixed::operator++(void)
{
	_value++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed &Fixed::operator--(void)
{
	_value--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return tmp;
}

bool Fixed::operator>(const Fixed &fixed) const
{
	return _value > fixed._value;
}

bool Fixed::operator<(const Fixed &fixed) const
{
	return _value < fixed._value;
}

bool Fixed::operator>=(const Fixed &fixed) const
{
	return _value >= fixed._value;
}

bool Fixed::operator<=(const Fixed &fixed) const
{
	return _value <= fixed._value;
}

bool Fixed::operator==(const Fixed &fixed) const
{
	return _value == fixed._value;
}

bool Fixed::operator!=(const Fixed &fixed) const
{
	return _value != fixed._value;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return a < b ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return a > b ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return a > b ? a : b;
}
