#ifndef C__CIRCLE_INTERN_H
#define C__CIRCLE_INTERN_H

#include "iostream"
#include "AForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"
#include "ShrubberyCreationForm.h"

class Intern {
private:
	AForm *forms[3];
public:
	Intern();
	Intern(const Intern &copy);
	Intern &operator=(const Intern &copy);
	virtual ~Intern();

	AForm *makeForm(std::string const &formName, std::string const &target);

	class FormNotFoundException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
};


#endif //C__CIRCLE_INTERN_H
