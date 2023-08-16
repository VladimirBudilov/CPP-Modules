#ifndef C__CIRCLE_MATERIASOURCE_H
#define C__CIRCLE_MATERIASOURCE_H

#include "iostream"
#include "IMateriaSource.h"

class MateriaSource : public IMateriaSource{

private:
	AMateria *materia[4];
	int count;

public:
	MateriaSource();
	MateriaSource(const MateriaSource &copy);
	MateriaSource &operator=(const MateriaSource &copy);
	virtual ~MateriaSource();

	void learnMateria(AMateria *m);
	AMateria *createMateria(std::string const &type);
};


#endif //C__CIRCLE_MATERIASOURCE_H
