#include "Bureaucrat.h"

int main( void ) {

	{
		Bureaucrat b1("B1", 1);
		b1.incrementGrade();
		std::cout << b1 << std::endl;
		b1.decrementGrade();
		std::cout << b1 << std::endl;
	}
	{
		Bureaucrat b1("B1", 150);
		b1.decrementGrade();
		std::cout << b1 << std::endl;
		b1.incrementGrade();
		std::cout << b1 << std::endl;
	}
	{
		//Bureaucrat b1("B1", 0);
		//Bureaucrat b2("B1", 151);
	}
	{
		try {
			Bureaucrat b1("B1", 0);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		try {
			Bureaucrat b1("B1", 151);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}
