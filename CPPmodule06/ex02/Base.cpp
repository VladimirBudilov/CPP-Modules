#include "Base.h"

Base::~Base()
{}

Base *generate(void)
{
	srand(time(NULL));
	Base *base;
	int i = rand() % 3;
	if (i == 0)
		base = new A;
	else if (i == 1)
		base = new B;
	else
		base = new C;
	return base;
}

void identify(Base *p)
{
	std::cout << "Pointer: ";
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

void identify(Base &p)
{
	std::cout << "Reference: ";
	try {
		Base a = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (std::exception &e) {
	}
	try {
		Base a = dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (std::exception &e) {
	}
	try {
		Base a = dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch (std::exception &e) {
	}
}



