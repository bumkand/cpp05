#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() :
	_name("Default"),
	_signed(false),
	_signGrade(1),
	_exeGrade(1)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string name, int signgrade, int exegrade) :
	_name(name),
	_signed(false),
	_signGrade(signgrade),
	_exeGrade(exegrade)
{
	if (signgrade < 1 || exegrade < 1)
		throw GradeTooHighException();
	if (signgrade > 150 || exegrade > 150)
		throw GradeTooLowException();
	std::cout << "Form " << _name << " parametrized constructor called" << std::endl;
}

Form::Form(const Form& other) :
	_name(other._name),
	_signed(other._signed),
	_signGrade(other._signGrade),
	_exeGrade(other._exeGrade)
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

const std::string Form::getName(void) const
{
	return _name;
}

bool Form::getSigned(void) const
{
	return _signed;
}

int Form::getSignGrade(void) const
{
	return _signGrade;
}

int Form::getExeGrade(void) const
{
	return _exeGrade;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

std::ostream& operator<<(std::ostream& out, const Form& other)
{
	if (other.getSigned() == 1)
		out << "Form " << other.getName() << ", sign grade " << other.getSignGrade() << ", execute grade " << other.getExeGrade() << ", signed: True" << other.getSigned();
	else
		out << "Form " << other.getName() << ", sign grade " << other.getSignGrade() << ", execute grade " << other.getExeGrade() << ", signed: False" << other.getSigned();
	return out;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= getSignGrade())
		_signed = true;
	else
		throw Form::GradeTooLowException();
}

