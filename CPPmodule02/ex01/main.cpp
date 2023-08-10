#include "Fixed.h"

int main( void ) {
	Fixed a;
	Fixed b( a );
	Fixed c;
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
/*	a.setRawBits( 42 );
	b.setRawBits( 21 );
	c.setRawBits( 84 );
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	system("leaks ex00");*/
	return 0;
}
