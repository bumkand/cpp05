#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() :
	_name("Default"),
	_signed(false),
	_signGrade(1),
	_exeGrade(1)
{
	//std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(std::string name, int signgrade, int exegrade) :
	_name(name),
	_signed(false),
	_signGrade(signgrade),
	_exeGrade(exegrade)
{
	if (signgrade < 1 || exegrade < 1)
		throw GradeTooHighException();
	if (signgrade > 150 || exegrade > 150)
		throw GradeTooLowException();
	//std::cout << "AForm " << _name << " parametrized constructor called" << std::endl;
}

AForm::AForm(const AForm& other) :
	_name(other._name),
	_signed(other._signed),
	_signGrade(other._signGrade),
	_exeGrade(other._exeGrade)
{
	//std::cout << "AForm copy constructor called" << std::endl;
}

AForm::~AForm()
{
	//std::cout << "AForm destructor called" << std::endl;
}

const std::string& AForm::getName(void) const
{
	return _name;
}

bool AForm::getSigned(void) const
{
	return _signed;
}

int AForm::getSignGrade(void) const
{
	return _signGrade;
}

int AForm::getExeGrade(void) const
{
	return _exeGrade;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char* AForm::DocumentNotSigned::what() const throw()
{
	return "Document is not signed";
}

std::ostream& operator<<(std::ostream& out, const AForm& other)
{
	if (other.getSigned() == 1)
		out << "AForm " << other.getName() << ", sign grade " << other.getSignGrade() << ", execute grade " << other.getExeGrade() << ", signed: True";
	else
		out << "AForm " << other.getName() << ", sign grade " << other.getSignGrade() << ", execute grade " << other.getExeGrade() << ", signed: False";
	return out;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= getSignGrade())
		_signed = true;
	else
		throw AForm::GradeTooLowException();
}

