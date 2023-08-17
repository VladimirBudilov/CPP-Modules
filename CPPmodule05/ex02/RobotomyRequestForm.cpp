#include "RobotomyRequestForm.h"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("RobotomyRequestForm", 72, 45)
{
	setTarget(target);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy)
{
	*this = copy;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	if (this == &copy)
		return *this;
	AForm::operator=(copy);
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > AForm::getGradeToExecute())
		throw GradeTooLowException();
	else if (getSigned() == "false")
		throw FormNotSignedException();
	std::cout << "* drilling noises *" << std::endl;
	if ((int)rand() % 2)
		std::cout << getTarget() << " has been robotomized successfully" << std::endl;
	else
		std::cout << getTarget() << " has been failure" << std::endl;
}
