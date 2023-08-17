#ifndef C__CIRCLE_ROBOTOMYREQUESTFORM_H
#define C__CIRCLE_ROBOTOMYREQUESTFORM_H

#include "AForm.h"
#include <cstdlib>

class RobotomyRequestForm : public AForm{
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string const &target);
	RobotomyRequestForm(const RobotomyRequestForm &copy);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);
	virtual ~RobotomyRequestForm();

	void execute(Bureaucrat const &executor) const;
	AForm *clone(std::string const &target) const;
};


#endif //C__CIRCLE_ROBOTOMYREQUESTFORM_H
