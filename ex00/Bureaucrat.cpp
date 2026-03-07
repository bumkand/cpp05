#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() :
	_name("Default"),
	_grade(1)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string& const name, int grade) :
	_name(name),
	_grade(grade)
{
	std::cout << "Bureaucrat parametrized constructor called" << std::endl;
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
	std::cout << "Bureaucrat destructor called" << std::endl;
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
	_grade -= 1;
}

void Bureaucrat::decrementGrade()
{
	_grade += 1;
}