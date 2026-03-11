#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() :
	_name("Default"),
	_grade(1)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) :
	_name(name),
	_grade(grade)
{
	if (_grade < 1)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
	std::cout << "Bureaucrat " << _name << " parametrized constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) :
	_name(other._name),
	_grade(other._grade)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

//Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
//{
//	if (this != &other)
//	{
//		_name = other._name;
//		_grade = other._grade;
//	}
//	std::cout << "Bureaucrat assigment operator called" << std::endl;
//	return *this;
//}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << _name << " destructor called" << std::endl;
}

std::string const Bureaucrat::getName(void) const
{
	return _name;
}

int Bureaucrat::getGrade(void) const
{
	return _grade;
}

void Bureaucrat::incrementGrade()
{
	if (_grade > 1)
		_grade -= 1;
	else
		throw GradeTooHighException();
}

void Bureaucrat::decrementGrade()
{
	if (_grade < 150)
		_grade += 1;
	else
		throw GradeTooLowException();
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	
	return "Grade is too low";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat& other)
{
	out << other.getName() << ", bureaucrat grade " << other.getGrade();
	return out;
}

void Bureaucrat::signForm(AForm& aform)
{
	try
	{
		aform.beSigned(*this);
		std::cout << _name << " signed " << aform.getName() << std::endl;
	}
	catch (AForm& aform)
	{
		std::cout << _name << " couldn't sign " << aform.getName() << " because sign grade is small " << aform.getSignGrade() << std::endl;
	}
}