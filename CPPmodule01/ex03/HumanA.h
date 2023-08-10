#ifndef C__CIRCLE_HUMANA_H
#define C__CIRCLE_HUMANA_H

#include "Weapon.h"

class HumanA {
private:
	std::string	name;
	Weapon		&weapon;
public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA();
	void attack();
};

#endif //C__CIRCLE_HUMANA_H
