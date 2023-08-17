#include "Form.h"

Form::Form()  : _name("Form"), _gradeToSign(150), _gradeToExecute(150)
{
	_signed = false;
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
		if (gradeToSign < 1 || gradeToExecute < 1)
			throw GradeTooHighException();
		else if (gradeToSign > 150 || gradeToExecute > 150)
			throw GradeTooLowException();
		_signed = false;
}

Form::Form(const Form &copy) : _name(copy._name), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
	*this = copy;
}

Form &Form::operator=(const Form &copy)
{
	if (this == &copy)
		return *this;
	_signed = copy._signed;
	return *this;
}

Form::~Form()
{

}

std::string const &Form::getName() const
{
	return _name;
}

std::string Form::getSigned() const
{
	return _signed ? "true" : "false";
}

int Form::getGradeToSign() const
{
	return _gradeToSign;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_signed = true;
}

int Form::getGradeToExecute() const
{
	return _gradeToExecute;
}

void Form::setSigned(bool signedValue)
{
	_signed = signedValue;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

const char *Form::FormNotSignedException::what() const throw()
{
	return "Form not signed";
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << form.getName() << " form, grade to sign " << form.getGradeToSign() << ", grade to execute " << form.getGradeToExecute() << ", signed " << form.getSigned();
	return out;
}


