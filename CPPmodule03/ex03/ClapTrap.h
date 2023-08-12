#ifndef C__CIRCLE_CLAPTRAP_H
#define C__CIRCLE_CLAPTRAP_H

#include "iostream"

class ClapTrap {
protected:
	std::string _name;
	int _hitPoints;
	int _energyPoints;
	int _attackDamage;
public:
	ClapTrap();
	ClapTrap(const std::string &name);
	ClapTrap(const ClapTrap &copy);
	ClapTrap &operator=(const ClapTrap &copy);
	~ClapTrap();

	virtual void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif //C__CIRCLE_CLAPTRAP_H
