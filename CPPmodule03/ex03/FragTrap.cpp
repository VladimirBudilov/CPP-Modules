#include "FragTrap.h"

FragTrap::FragTrap() : ClapTrap() {
	std::cout << "FragTrap default constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
	std::cout << "FragTrap name constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy) {
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &copy) {
	std::cout << "FragTrap assignation operator called" << std::endl;
	ClapTrap::operator=(copy);
	return (*this);
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::highFivesGuys( void ) {
	std::cout << "FragTrap " << _name << " is asking for high fives" << std::endl;
}
