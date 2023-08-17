#include "Bureaucrat.h"
#include "../ex02/Bureaucrat.h"


Bureaucrat::Bureaucrat() : _name("Bureaucrat"), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	*this = copy;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
	if (this == &copy)
		return *this;
	_grade = copy._grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
}

std::string const &Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::incrementGrade()
{
	try {
		if (_grade - 1 < 1)
			throw GradeTooHighException();
		_grade--;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void Bureaucrat::decrementGrade()
{
	try {
		if (_grade + 1 > 150)
			throw GradeTooLowException();
		_grade++;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}


const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return out;
}
