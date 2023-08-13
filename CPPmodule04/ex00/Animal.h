#ifndef C__PROJECT_ANIMAL_H
#define C__PROJECT_ANIMAL_H

#include "iostream"

class Animal {
protected:
    std::string _type;
public:
    Animal();
    ~Animal();
    Animal(const Animal &copy);
    Animal &operator=(const Animal &copy);

    virtual void makeSound() const;
    virtual std::string getType() const;
};


#endif //C__PROJECT_ANIMAL_H
