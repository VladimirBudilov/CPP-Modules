#ifndef C__PROJECT_ANIMAL_H
#define C__PROJECT_ANIMAL_H

#include "iostream"
#include "Brain.h"

class Animal {
public:
    Animal();
    Animal(const Animal &copy);
    Animal &operator=(const Animal &copy);
	virtual ~Animal();

    virtual void makeSound() const;
    virtual std::string getType() const;
protected:
	std::string _type;
};


#endif //C__PROJECT_ANIMAL_H
