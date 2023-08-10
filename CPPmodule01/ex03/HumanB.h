#ifndef C__CIRCLE_HUMANB_H
#define C__CIRCLE_HUMANB_H

#include "Weapon.h"

class HumanB {
private:
	std::string	name;
	Weapon		*weapon;
public:
	HumanB(std::string name);
	~HumanB();
	void attack();
	void setWeapon(Weapon &weapon);
};

#endif //C__CIRCLE_HUMANB_H
