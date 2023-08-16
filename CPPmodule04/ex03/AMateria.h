#ifndef C__CIRCLE_AMATERIA_H
#define C__CIRCLE_AMATERIA_H

#include "iostream"
#include "ICharacter.h"

class ICharacter;

class AMateria{
protected:
	std::string _type;
public:
	AMateria();
	AMateria(const AMateria &copy);
	virtual AMateria &operator=(const AMateria &copy);
	virtual ~AMateria();

	AMateria(std::string const & type);
	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};


#endif //C__CIRCLE_AMATERIA_H
