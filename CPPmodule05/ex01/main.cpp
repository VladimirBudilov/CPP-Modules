#include "Bureaucrat.h"
#include "Form.h"

int main( void ) {

	{
		try{
			//Form f1("F1", 1, 0);
			//Form f2("F1", 1, 151);
			Form f3("F1", 0, 1);
			Form f4("F1", 151, 1);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		Bureaucrat b1("B1", 1);
		Form f1("F1", 1, 1);
		std::cout << f1 << std::endl;
		b1.signForm(f1);
		std::cout << f1 << std::endl;
	}
	std::cout << std::endl;
	{
		Bureaucrat b1("B1", 2);
		Form f1("F1", 1, 1);
		std::cout << f1 << std::endl;
		b1.signForm(f1);
		std::cout << f1 << std::endl;
	}

	return 0;
}
