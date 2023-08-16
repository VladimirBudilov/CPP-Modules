#include "Animal.h"

Animal::Animal() {
    std::cout << "Animal constructor called" << std::endl;
    _type = "Animal";
}

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal &copy) {
    std::cout << "Animal copy constructor called" << std::endl;
    *this = copy;
}

Animal &Animal::operator=(const Animal &copy) {
    std::cout << "Animal assignation operator called" << std::endl;
    if (this != &copy)
        _type = copy._type;
    return *this;
}

void Animal::makeSound() const {
    std::cout << "Animal sound" << std::endl;
}

std::string Animal::getType() const {
    return _type;
}
