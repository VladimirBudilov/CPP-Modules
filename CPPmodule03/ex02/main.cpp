#include "ScavTrap.h"
#include "FragTrap.h"

int main( void ) {

	std::cout << "### TESTING CLAPTRAP ###\n" << std::endl;
	{
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
		b.beRepaired(3);
		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	}
	std::cout << "\n\n### TESTING SCAVTRAP ###\n" << std::endl;
	{
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		ScavTrap c;
		ScavTrap d("SavageBiba");

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		c.attack("SavageBoba");
		c.beRepaired(22);
		c.takeDamage(21);
		c.beRepaired(22);
		c.guardGate();
		d.attack("SavageBiba-clone");
		d.takeDamage(101);
		d.takeDamage(15);
		d.attack("SavageBiba-clone");
		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	}
	std::cout << "\n\n### TESTING FRAGTRAP ###\n" << std::endl;
	{
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		FragTrap e;
		FragTrap f("Biba");

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		e.highFivesGuys();
		e.attack("some random Boba");
		e.takeDamage(101);
		e.takeDamage(1);
		e.attack("some random Boba");
		f.highFivesGuys();
		// for(int i = 0; i < 101; i++)
		// 	f.attack("FragTrap-clone");
		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	}
	return 0;
}
