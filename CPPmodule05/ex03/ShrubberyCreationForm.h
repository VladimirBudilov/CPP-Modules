#ifndef C__CIRCLE_SHRUBBERYCREATIONFORM_H
#define C__CIRCLE_SHRUBBERYCREATIONFORM_H

#include "iostream"
#include <fstream>
#include "AForm.h"
class ShrubberyCreationForm : public AForm{

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string const &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &copy);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);
	virtual ~ShrubberyCreationForm();

	void execute(Bureaucrat const &executor) const;
	AForm *clone(std::string const &target) const;

};


#endif //C__CIRCLE_SHRUBBERYCREATIONFORM_H
