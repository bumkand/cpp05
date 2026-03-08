#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	a("Andy", 150);
		std::cout << a << std::endl << std::endl;

		Bureaucrat	b("Bilbo", 1);
		std::cout << b << std::endl << std::endl;

		Bureaucrat	c("Ciril", 123);
		std::cout << c << std::endl;
		while (c.getGrade() > 1)
			c.incrementGrade();
		std::cout << c << std::endl;
		while (c.getGrade() < 150)
			c.decrementGrade();
		std::cout << c << std::endl << std::endl;

		Bureaucrat	d("Didi", 1);
		std::cout << d << std::endl;
		d.incrementGrade();
		std::cout << d << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat	d("Didi", 150);
		std::cout << d << std::endl;
		d.decrementGrade();
		std::cout << d << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat	d("Didi", 151);
		std::cout << d << std::endl;
		d.decrementGrade();
		std::cout << d << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}