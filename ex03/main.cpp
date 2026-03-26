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
	rrf = someRandomIntern.makeForm("shrubbery ", "Bender");
	if (rrf == NULL)
		return 1;

	Bureaucrat	j("Pankrac", 10);

	j.signForm(*rrf);
	j.executeForm(*rrf);

	delete rrf;
	return 0;
}