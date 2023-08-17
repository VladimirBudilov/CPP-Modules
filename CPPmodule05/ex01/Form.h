#ifndef C__CIRCLE_FORM_H
#define C__CIRCLE_FORM_H

#include "iostream"
#include "Bureaucrat.h"

class Bureaucrat;

class Form {
private:
	std::string const _name;
	bool _signed;
	int const _gradeToSign;
	int const _gradeToExecute;
public:
	Form();
	Form(std::string const &name, int gradeToSign, int gradeToExecute);
	Form(const Form &copy);
	Form &operator=(const Form &copy);
	virtual ~Form();

	std::string const &getName() const;
	std::string getSigned() const;
	void setSigned(bool signedValue);
	int getGradeToSign() const;
	int getGradeToExecute() const;
	void beSigned(const Bureaucrat &bureaucrat);

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

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif //C__CIRCLE_FORM_H
