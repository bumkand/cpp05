#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	srand(time(0));
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("presidential pardon", "");
	if (rrf != NULL)
	{
		Bureaucrat	j("Pankrac", 10);
		try
		{
			j.signForm(*rrf);
			j.executeForm(*rrf);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}

		delete rrf;
	}

	rrf = someRandomIntern.makeForm("presidential pardon", "Alex");
	if (rrf != NULL)
	{
		Bureaucrat	k("Servac", 5);
		try
		{
			k.signForm(*rrf);
			rrf->execute(k);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		delete rrf;
	}
	
	return 0;
}
