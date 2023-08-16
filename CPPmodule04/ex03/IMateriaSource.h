#ifndef C__CIRCLE_IMATERIASOURCE_H
#define C__CIRCLE_IMATERIASOURCE_H

#include "iostream"
#include "AMateria.h"

class IMateriaSource
{
public:
	virtual ~IMateriaSource() {}
	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif //C__CIRCLE_IMATERIASOURCE_H
