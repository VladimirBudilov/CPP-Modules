#include "Zombie.h"

Zombie::Zombie()
{
	_name = "defaultZombieName";
}

Zombie::~Zombie()
{
	std::cout << _name << " is dead" << std::endl;
}

void Zombie::announce()
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
	_name = name;
}

std::string Zombie::getName()
{
	return _name;
}

