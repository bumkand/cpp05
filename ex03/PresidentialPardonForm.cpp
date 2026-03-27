#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
	AForm("PresidentialPardonForm", 25, 5),
	_target("Default_target")
{
	//std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	AForm("PresidentialPardonForm", 25, 5),
	_target(target)
{
	//std::cout << "PresidentialPardonForm parametrized constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) :
	AForm(other),
	_target(other._target)
{
	//std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

//PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
//{
//	if (this != &other)
//	{
//		_target = other._target;
//	}
//	//std::cout << "PresidentialPardonForm assigment operator called" << std::endl;
//	return *this;
//}

PresidentialPardonForm::~PresidentialPardonForm()
{
	//std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (getSigned() == false)
		throw AForm::DocumentNotSigned();
	if (executor.getGrade() > getExeGrade())
		throw AForm::GradeTooLowException();

	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
