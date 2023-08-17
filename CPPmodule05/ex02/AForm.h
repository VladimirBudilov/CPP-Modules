#ifndef C__CIRCLE_AFORM_H
#define C__CIRCLE_AFORM_H

#include "iostream"
#include "Bureaucrat.h"

class Bureaucrat;

class AForm {
private:
	std::string const _name;
	std::string _target;
	bool _isSigned;
	int const _gradeToSign;
	int const _gradeToExecute;
public:
	AForm();
	AForm(std::string const &name, int const gradeToSign, int const gradeToExecute);
	AForm(const AForm &copy);
	virtual AForm &operator=(const AForm &copy);
	virtual ~AForm();

	virtual std::string const &getTarget() const;
	virtual void setTarget(std::string const &target);
	virtual std::string const &getName() const;
	virtual std::string getSigned() const;
	virtual void setSigned(bool isSigned);
	virtual int getGradeToSign() const;
	virtual int getGradeToExecute() const;
	virtual void beSigned(const Bureaucrat &bureaucrat);
	virtual void execute(Bureaucrat const &executor) const = 0;

	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class FormNotSignedException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
};


#endif //C__CIRCLE_AFORM_H
