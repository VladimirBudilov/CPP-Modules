#ifndef C__PROJECT_CAT_H
#define C__PROJECT_CAT_H

#include "Animal.h"

class Cat : public Animal{
public:
    Cat();
    virtual ~Cat();
    Cat(const Cat &copy);
    Cat &operator=(const Cat &copy);
    void makeSound() const;
};


#endif //C__PROJECT_CAT_H
