#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
//#include <bits/stdc++.h>
#include <exception>

class Bureaucrat
{
	private:
		std::string const	_name;
		int					_grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string& const name, int grade);
		Bureaucrat(const Bureaucrat& other);
		//Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();
		
		std::string const getName(void) const;
		int getGrade(void) const;
		void incrementGrade();
		void decrementGrade();

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const noexcept
				{
					std::cout << "Grade is too high" << std::endl;
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const noexcept
				{
					std::cout << "Grade is too low" << std::endl;
				}
		};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat& other);

#endif