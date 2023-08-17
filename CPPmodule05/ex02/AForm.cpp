#include "AForm.h"
#include "../ex03/AForm.h"

AForm::AForm() : _name("AForm"), _target("some target"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{

}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute) : _name(name), _target("some target"),
																			 _isSigned(false),
																			 _gradeToSign(gradeToSign),
																			 _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &copy) : _name(copy._name), _isSigned(copy._isSigned), _gradeToSign(copy._gradeToSign),
								  _gradeToExecute(copy._gradeToExecute)
{
	*this = copy;
}

AForm &AForm::operator=(const AForm &copy)
{
	if (this == &copy)
		return *this;
	_isSigned = copy._isSigned;
	_target = copy._target;
	return *this;
}

AForm::~AForm()
{

}

std::string const &AForm::getName() const
{
	return _name;
}

std::string AForm::getSigned() const
{
	return _isSigned ? "true" : "false";
}

int AForm::getGradeToSign() const
{
	return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

void AForm::setSigned(bool isSigned)
{
	_isSigned = isSigned;
}

std::string const &AForm::getTarget() const
{
	return _target;
}

void AForm::setTarget(const std::string &target)
{
	_target = target;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

std::ostream &operator<<(std::ostream &out, const AForm &aForm)
{
	out << aForm.getName() << ", form grade to sign " << aForm.getGradeToSign() << ", form grade to execute "
		<< aForm.getGradeToExecute() << ", form is signed " << aForm.getSigned() << std::endl;
	return out;
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "Form not signed";
}
