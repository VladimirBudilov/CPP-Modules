#include "Bureaucrat.h"
#include "AForm.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"

int main(void)
{
	AForm *formTree = new ShrubberyCreationForm("home");
	AForm *formRobotomy = new RobotomyRequestForm("me");
	AForm *formPardon = new PresidentialPardonForm("you");
	Bureaucrat bureaucratLowLVL("bureaucratLowLVL lowLvl", 150);
	Bureaucrat bureaucratHighLVL("bureaucratLowLVL highLvl", 1);
	Bureaucrat bureaucratMidLVL("bureaucratLowLVL midLvl", 75);

	bureaucratLowLVL.signForm(*formTree);
	bureaucratHighLVL.signForm(*formRobotomy);
	bureaucratHighLVL.signForm(*formPardon);
	std::cout << std::endl;
	bureaucratHighLVL.executeForm(*formTree);
	bureaucratMidLVL.executeForm(*formRobotomy);
	bureaucratHighLVL.executeForm(*formPardon);
	return 0;
}
