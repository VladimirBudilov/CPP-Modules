#ifndef C__CIRCLE_DIAMONDTRAP_H
#define C__CIRCLE_DIAMONDTRAP_H

#include "FragTrap.h"
#include "ScavTrap.h"

class DiamondTrap : public FragTrap, public ScavTrap{
private:
	std::string _name;
public:
	DiamondTrap();
	DiamondTrap(const std::string &name);
	DiamondTrap(const DiamondTrap &copy);
	DiamondTrap &operator=(const DiamondTrap &copy);
	~DiamondTrap();

	void attack(const std::string &target);
	void whoAmI();
};


#endif //C__CIRCLE_DIAMONDTRAP_H
