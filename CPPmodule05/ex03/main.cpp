#include "Bureaucrat.h"
#include "AForm.h"
#include "Intern.h"

int main(void)
{
	{
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	}
	{
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
	}
	try{
		{
			Intern someRandomIntern;
			AForm* rrf;
			rrf = someRandomIntern.makeForm("shrubbery", "Bender");
		}
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	//system("leaks ex03");
	return 0;
}
