#include "ClapTrap.h"

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
	std::cout << "ClapTrap Assignation operator called" << std::endl;
	if (this != &copy) {
		_name = copy._name;
		_hitPoints = copy._hitPoints;
		_energyPoints = copy._energyPoints;
		_attackDamage = copy._attackDamage;
	}
	return (*this);
}

ClapTrap::ClapTrap(const std::string &name)
{
	std::cout << "ClapTrap name constructor called" << std::endl;
	_name = name;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
	_name = "DefaultName";
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (_hitPoints <= 0) {
		std::cout << "ClapTrap " << _name << " is dead and can't attack" << std::endl;
		return;
	}
	if (_energyPoints <= 0) {
		std::cout << "ClapTrap " << _name << " has not enough energy to attack" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!"
			  << std::endl;
	_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints <= 0) {
		std::cout << "ClapTrap " << _name << " is already dead" << std::endl;
		return;
	}
	if ((int) amount > _hitPoints) {
		std::cout << "ClapTrap " << _name << " takes " << _hitPoints << " damage" << std::endl;
		_hitPoints = 0;
	} else {
		std::cout << "ClapTrap " << _name << " takes " << amount << " damage" << std::endl;
		_hitPoints -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints <= 0) {
		std::cout << "ClapTrap " << _name << " is dead and can't be repaired" << std::endl;
		return;
	}
	if (_energyPoints <= 0) {
		std::cout << "ClapTrap " << _name << " has not enough energy to be repaired" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << _name << " is repaired by " << amount << " points" << std::endl;
	_hitPoints += amount;
	_energyPoints--;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	*this = copy;
}
