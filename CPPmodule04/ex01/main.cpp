#include "Cat.h"
#include "Dog.h"

int main()
{
	Dog basic;
	std::cout << std::endl;
	{
		Dog tmp = basic;
		std::cout << std::endl;
	}
	std::cout << std::endl;
	Cat basic2;
	{
		Cat tmp = basic2;
	}
	std::cout << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	const Animal	*animal_array[4];
	std::cout << std::endl;
	// Half with dogs
	for (int i = 0; i < 2; i++)
		animal_array[i] = new Dog();
	std::cout << std::endl;

	// Half with cats
	for (int i = 2; i < 4; i++)
		animal_array[i] = new Cat();
	std::cout << std::endl;

	for (int i = 0; i < 4; i++)
		delete animal_array[i];
	system("leaks ex01");
    return 0;
}
