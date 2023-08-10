#include "HumanB.h"

HumanB::HumanB(std::string name)
{
	HumanB::name = name;
	HumanB::weapon = NULL;
}

HumanB::~HumanB()
{

}

void HumanB::attack()
{
	if (HumanB::weapon)
		std::cout << HumanB::name << " attacks with their " << HumanB::weapon->getType() << std::endl;
	else
		std::cout << HumanB::name << " attacks with his bare hands" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	HumanB::weapon = &weapon;
}
