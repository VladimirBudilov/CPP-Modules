#include "Cure.h"

Cure::Cure()
{
	_type = "cure";
}

Cure::Cure(const Cure &copy) : AMateria(copy)
{

}

Cure::~Cure()
{

}

Cure &Cure::operator=(const Cure &copy)
{
	if (this == &copy)
		return *this;
	AMateria::operator=(copy);
	return *this;
}

AMateria *Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
