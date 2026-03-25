#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	AForm	*form1 = new ShrubberyCreationForm("Shrubb1");
	AForm	*form2 = new RobotomyRequestForm("Robot1");
	AForm	*form3 = new PresidentialPardonForm("Presid1");
	Bureaucrat	l("Pankrac", 4);
	Bureaucrat	k("Servac", 50);
	Bureaucrat	j("Bonifac", 150);
	
	srand(time(0));

	std::cout << std::endl;
	try
	{
		l.signForm(*form1);
		l.executeForm(*form1);
		
		k.signForm(*form1);
		k.executeForm(*form1);

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
		l.signForm(*form1);
		form1->execute(l);
		
		k.signForm(*form1);
		form1->execute(k);

		j.signForm(*form1);
		form1->execute(j);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		l.signForm(*form2);
		l.executeForm(*form2);
		
		k.signForm(*form2);
		k.executeForm(*form2);

		j.signForm(*form2);
		j.executeForm(*form2);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		l.signForm(*form2);
		form2->execute(l);
		
		k.signForm(*form2);
		form2->execute(k);

		j.signForm(*form2);
		form2->execute(j);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		l.signForm(*form3);
		l.executeForm(*form3);
		
		k.signForm(*form3);
		k.executeForm(*form3);

		j.signForm(*form3);
		j.executeForm(*form3);
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
		
		k.signForm(*form3);
		form3->execute(k);

		j.signForm(*form3);
		form3->execute(j);
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