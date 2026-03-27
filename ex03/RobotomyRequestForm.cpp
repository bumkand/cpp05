#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :
	AForm("RobotomyRequestForm", 72, 45),
	_target("Default_target")
{
	//std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	AForm("RobotomyRequestForm", 72, 45),
	_target(target)
{
	//std::cout << "RobotomyRequestForm parametrized constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) :
	AForm(other),
	_target(other._target)
{
	//std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

//RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
//{
//	if (this != &other)
//	{
//		_target = other._target;
//	}
//	//std::cout << "RobotomyRequestForm assigment operator called" << std::endl;
//	return *this;
//}

RobotomyRequestForm::~RobotomyRequestForm()
{
	//std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (getSigned() == false)
		throw AForm::DocumentNotSigned();
	if (executor.getGrade() > getExeGrade())
		throw AForm::GradeTooLowException();

	std::cout << "* drilling noise *" << std::endl;
	if ((rand() % 2) == 0)
		std::cout << _target << " has been robotomized" << std::endl;
	else
		std::cout << _target << " robotomy failed" << std::endl;
}
