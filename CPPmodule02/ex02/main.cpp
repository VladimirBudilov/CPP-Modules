#include "Fixed.h"

std::ostream    &operator<<(std::ostream &o, Fixed const &fixed);

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << (a != b) * 1<< std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	a = b;
	std::cout << a / Fixed() << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}
