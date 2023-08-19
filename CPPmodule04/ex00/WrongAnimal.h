#ifndef C__CIRCLE_WRONGANIMAL_H
#define C__CIRCLE_WRONGANIMAL_H

#include "iostream"

class WrongAnimal {
public:
	WrongAnimal();
	virtual ~WrongAnimal();
	WrongAnimal(const WrongAnimal &copy);
	WrongAnimal &operator=(const WrongAnimal &copy);
	void makeSound() const;
	virtual std::string getType() const;
protected:
	std::string _type;
};


#endif //C__CIRCLE_WRONGANIMAL_H
