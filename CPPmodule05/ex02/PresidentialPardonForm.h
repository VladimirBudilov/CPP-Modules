#ifndef C__CIRCLE_PRESIDENTIALPARDONFORM_H
#define C__CIRCLE_PRESIDENTIALPARDONFORM_H

#include "AForm.h"

class PresidentialPardonForm : public AForm{
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string const &target);
	PresidentialPardonForm(const PresidentialPardonForm &copy);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);
	virtual ~PresidentialPardonForm();

	void execute(Bureaucrat const &executor) const;
};

#endif //C__CIRCLE_PRESIDENTIALPARDONFORM_H
