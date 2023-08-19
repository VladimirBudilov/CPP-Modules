#include "Cat.h"

Cat::Cat() : Animal(), _brain(nullptr)
{
	std::cout << "Cat constructor called" << std::endl;
	_type = "Cat";
	_brain = new Brain();
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete _brain;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	std::cout << "Cat copy constructor called" << std::endl;
	_brain = new Brain();
	*_brain = *copy._brain;
}

Cat &Cat::operator=(const Cat &copy)
{
	std::cout << "Cat assignation operator called" << std::endl;
	if (this == &copy)
		return *this;
	Animal::operator=(copy);
	delete _brain;
	_brain = new Brain();
	_brain->operator=(*copy._brain);
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}
