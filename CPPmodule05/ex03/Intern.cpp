#include "Intern.h"

Intern::Intern() {
	forms[0] = new RobotomyRequestForm();
	forms[1] = new PresidentialPardonForm();
	forms[2] = new ShrubberyCreationForm();
}

Intern::Intern(const Intern &copy) {
	forms[0] = new RobotomyRequestForm();
	forms[1] = new PresidentialPardonForm();
	forms[2] = new ShrubberyCreationForm();
	*this = copy;
}

Intern &Intern::operator=(const Intern &copy) {
	if (this == &copy)
		return *this;
	return *this;
}

Intern::~Intern() {
	for (int i = 0; i < 3; ++i) {
		delete forms[i];
	}
}

AForm *Intern::makeForm(std::string const &formName, std::string const &target) {
	std::string formNames[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	for (int i = 0; i < 3; ++i) {
		if (formName == formNames[i]) {
			std::cout << "Intern creates " << formName << std::endl;
			AForm *newForm = forms[i]->clone(target);
			return newForm;
		}
	}
	throw FormNotFoundException();
}

const char *Intern::FormNotFoundException::what() const throw() {
	return "Form not found";
}

