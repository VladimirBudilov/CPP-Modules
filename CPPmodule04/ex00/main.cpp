#include "Cat.h"
#include "Dog.h"
#include "WrongCat.h"


int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
	delete meta;
	delete j;
	delete i;

	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();
	std::cout << wrongCat->getType() << " " << std::endl;
	wrongCat->makeSound(); //will output the WrongAnimal sound!
	wrongMeta->makeSound();
	delete wrongMeta;
	delete wrongCat;
    return 0;
}
