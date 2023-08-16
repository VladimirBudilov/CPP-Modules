#ifndef C__PROJECT_DOG_H
#define C__PROJECT_DOG_H

#include "Animal.h"

class Dog : public Animal{
    public:
    Dog();
    virtual ~Dog();
    Dog(const Dog &copy);
    Dog &operator=(const Dog &copy);
    void makeSound() const;

};


#endif //C__PROJECT_DOG_H
