#include "WrongCat.h"

#include "WrongCat.h"

WrongCat::WrongCat() {
	std::cout << "WrongCat constructor called" << std::endl;
	_type = "WrongCat";
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) {
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = copy;
}

WrongCat &WrongCat::operator=(const WrongCat &copy) {
	std::cout << "WrongCat assignation operator called" << std::endl;
	if (this != &copy)
		WrongAnimal::operator=(copy);
	return *this;
}

std::string WrongCat::getType() const {
	return _type;
}

void WrongCat::makeSound() const
{
	std::cout << "WrongMeow" << std::endl;
}
