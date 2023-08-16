#ifndef C__CIRCLE_ICE_H
#define C__CIRCLE_ICE_H

#include "AMateria.h"
#include "ICharacter.h"

class Ice : public AMateria {
public:
	Ice();
	Ice(const Ice &copy);
	Ice &operator=(const Ice &copy);
	virtual ~Ice();

	virtual AMateria *clone() const;
	virtual void use(ICharacter &target);
};

#endif //C__CIRCLE_ICE_H
