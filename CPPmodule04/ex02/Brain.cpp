#include "Brain.h"

Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
	_ideas = new std::string[100];
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
	delete[] _ideas;
}

Brain::Brain(const Brain &copy)
{
	std::cout << "Brain copy constructor called" << std::endl;
	_ideas = new std::string[copy._ideas->length()];
	for (int i = 0; i < (int )_ideas->length(); ++i)
		_ideas[i] = copy._ideas[i];
}

Brain &Brain::operator=(const Brain &copy)
{
	std::cout << "Brain assignation operator called" << std::endl;
	if (this == &copy)
		return *this;
	delete[] _ideas;
	_ideas = new std::string[copy._ideas->length()];
	for (int i = 0; i < (int )_ideas->length(); ++i)
		_ideas[i] = copy._ideas[i];
	return *this;
}


