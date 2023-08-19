#include "Dog.h"

Dog::Dog()
{
	std::cout << "Dog constructor called" << std::endl;
	_type = "Dog";
	_brain = new Brain();
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete _brain;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << "Dog copy constructor called" << std::endl;
	_brain = new Brain();
	*_brain = *copy._brain;
}

Dog &Dog::operator=(const Dog &copy)
{
	std::cout << "Dog assignation operator called" << std::endl;
	if (this == &copy)
		return *this;
	Animal::operator=(copy);
	delete _brain;
	_brain = new Brain();
	_brain->operator=(*copy._brain);
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Gaw" << std::endl;
}
