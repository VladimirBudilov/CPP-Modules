#include "ShrubberyCreationForm.h"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("ShrubberyCreationForm", 145, 137)
{
	setTarget(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	if (this == &copy)
		return *this;
	AForm::operator=(copy);
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{

	if (executor.getGrade() > AForm::getGradeToExecute())
		throw GradeTooLowException();
	else if (getSigned() == "false")
		throw FormNotSignedException();
	std::ofstream outputFile(getTarget() + "_shrubbery");
	if (outputFile.is_open()) {
		outputFile << "       ccee88oo\n";
		outputFile << "  C8O8O8Q8PoOb o8oo\n";
		outputFile << " dOB69QO8PdUOpugoO9bD\n";
		outputFile << "CgggbU8OU qOp qOdoUOdcb\n";
		outputFile << "O o88oUodcb  dUdUO8PdU\n";
		outputFile << "   6OuU  /p u gcoUodpP\n";
		outputFile << "     \\//  /douUP\n";
		outputFile << "       \\\\////\n";
		outputFile << "        |||/\\\n";
		outputFile << "        |||\\/\\\n";
		outputFile << "        |||||\n";
		outputFile << "  .....//|||||\\....\n";
	}
}

AForm *ShrubberyCreationForm::clone(const std::string &target) const
{
	return new ShrubberyCreationForm(target);
}

