#ifndef C__CIRCLE_WRONGCAT_H
#define C__CIRCLE_WRONGCAT_H

#include "WrongAnimal.h"

class WrongCat : public WrongAnimal{
	public:
	WrongCat();
	~WrongCat();
	WrongCat(const WrongCat &copy);
	WrongCat &operator=(const WrongCat &copy);
	std::string getType() const;
	void makeSound() const;
};


#endif //C__CIRCLE_WRONGCAT_H
