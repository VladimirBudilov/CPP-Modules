#include "AMateria.h"

std::string const &AMateria::getType() const
{
	return _type;
}

AMateria::AMateria(std::string const &type) : _type(type)
{
}

void AMateria::use(ICharacter &target)
{
	(void)target;
}

AMateria::~AMateria()
{
}

AMateria &AMateria::operator=(const AMateria &copy)
{
	if (this == &copy) {
		std::cout << "Materia is same" << std::endl;
		return *this;
	}
	std::cout<< "you cannot assign different materia" << std::endl;
	return *this;
}

AMateria::AMateria(const AMateria &copy)
{
	_type = copy._type;
}

AMateria::AMateria()
{

}
