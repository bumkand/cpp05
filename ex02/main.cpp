#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	AForm	*form1 = new ShrubberyCreationForm("Shrubb1");
	AForm	*form2 = new ShrubberyCreationForm("Shrubb2");
	AForm	*form3 = new ShrubberyCreationForm("Shrubb3");
	Bureaucrat	j("Pankrac", 130);
	Bureaucrat	k("Servac", 140);
	Bureaucrat	l("Bonifac", 150);

	std::cout << std::endl;
	try
	{
		j.signForm(*form1);
		j.executeForm(*form1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		k.signForm(*form2);
		form2->execute(k);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		l.signForm(*form3);
		form3->execute(l);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	delete form1;
	delete form2;
	delete form3;
}