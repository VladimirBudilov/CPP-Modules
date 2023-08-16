#ifndef C__CIRCLE_CURE_H
#define C__CIRCLE_CURE_H

#include "AMateria.h"
#include "ICharacter.h"

class Cure : public AMateria {
public:
	Cure();
	Cure(const Cure &copy);
	Cure &operator=(const Cure &copy);
	virtual ~Cure();

	virtual AMateria *clone() const;
	virtual void use(ICharacter &target);
};


#endif //C__CIRCLE_CURE_H
