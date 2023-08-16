#include "MateriaSource.h"

MateriaSource::MateriaSource() : count(0)
{
	for (int i = 0; i < 4; ++i)
		materia[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	*this = copy;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &copy)
{
	if (this == &copy)
		return *this;
	for (int i = 0; i < 4; ++i)
	{
		if (materia[i])
			delete materia[i];
		materia[i] = copy.materia[i]->clone();
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; ++i)
		if (materia[i])
			delete materia[i];
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (count < 4)
	{
		materia[count] = m;
		++count;
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; ++i)
	{
		if (materia[i] && materia[i]->getType() == type)
			return materia[i]->clone();
	}
	return NULL;
}
