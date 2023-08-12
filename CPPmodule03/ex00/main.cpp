#include "ClapTrap.h"

int main( void ) {

	std::cout << "\033[34mConstructing\033[0m" << std::endl;
	ClapTrap a;
	ClapTrap b("Biba");

	std::cout << "\033[34mTesting\033[0m" << std::endl;
	a.attack("Boba");
	a.takeDamage(10);
	a.takeDamage(10);
	a.beRepaired(5);
	a.attack("Boba");
	b.beRepaired(3);
	for (int i = 0; i < 12; i++)
		b.attack("Baba");
	b.beRepaired(3);
	std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	return 0;
}
