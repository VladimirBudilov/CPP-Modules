#ifndef C__CIRCLE_SCAVTRAP_H
#define C__CIRCLE_SCAVTRAP_H

#include "iostream"
#include "ClapTrap.h"

class ScavTrap : public virtual ClapTrap {

public:
	ScavTrap();
	ScavTrap(const std::string &name);
	ScavTrap(const ScavTrap &copy);
	ScavTrap &operator=(const ScavTrap &copy);
	~ScavTrap();

	void attack(const std::string &target);
	void guardGate();
};


#endif //C__CIRCLE_SCAVTRAP_H
