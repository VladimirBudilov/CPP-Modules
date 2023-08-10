#include "Weapon.h"

Weapon::Weapon(std::string type)
{
	Weapon::_type = type;
}

Weapon::~Weapon()
{

}

const std::string &Weapon::getType()
{
	return _type;
}

void Weapon::setType(std::string type)
{
	Weapon::_type = type;
}
