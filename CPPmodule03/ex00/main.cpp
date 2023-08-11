#include "ClapTrap.h"

int main( void ) {

	ClapTrap clapTrap("ClapTrap");
	ClapTrap clapTrap1(clapTrap);
	ClapTrap clapTrap2("ClapTrap2");

	clapTrap.attack("ClapTrap2");
	clapTrap2.takeDamage(5);
	clapTrap2.beRepaired(5);
	clapTrap.attack("ClapTrap2");
	clapTrap2.takeDamage(100);
	clapTrap2.beRepaired(100);
	clapTrap.attack("ClapTrap2");
	clapTrap2.takeDamage(1);
	clapTrap2.beRepaired(1);
	for(int i = 0; i < 12; i++)
		clapTrap1.attack("ClapTrap2");
	return 0;
}
