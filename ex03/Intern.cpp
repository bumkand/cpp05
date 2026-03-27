#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor" << std::endl;
}

Intern::Intern(const Intern& other)
{
	(void) other;
	std::cout << "Intern copy constructor" << std::endl;
}

Intern& Intern::operator=(const Intern& other)
{
	(void) other;
	std::cout << "Intern assigment operator called" << std::endl;
	return *this;
}

Intern::~Intern()
{
	std::cout << "Intern destructor" << std::endl;
}

AForm* shrubbform(std::string target)
{
	AForm* form = new ShrubberyCreationForm(target);
	return form;
}

AForm* robotomyform(std::string target)
{
	AForm* form = new RobotomyRequestForm(target);
	return form;
}

AForm* presidential(std::string target)
{
	AForm* form = new PresidentialPardonForm(target);
	return form;
}

AForm* Intern::makeForm(std::string name, std::string target)
{
	std::string	form[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int			num = 0;

	if (target == "")
	{
		std::cerr << "Target is missing" << std::endl;
		return NULL;
	}
	while (num < 3 && name != form[num])
		num++;
	
	//switch (num)
	//{
	//	case 0:
	//		return shrubbform(target);
	//	case 1:
	//		return robotomyform(target);
	//	case 2:
	//		return presidential(target);
	//	default:
	//	{
	//		std::cerr << "This type of form doesn't exist" << std::endl;
	//		return NULL;
	//	}
	//}

	typedef AForm* (*AFormMemPtr)(std::string target);
	AFormMemPtr	function[] = {&shrubbform, &robotomyform, &presidential};
	if (num == 3)
	{
		std::cerr << "This type of form doesn't exist" << std::endl;
		return NULL;
	}
	return function[num](target);
}
