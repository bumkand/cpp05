#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
//#include <bits/stdc++.h>
#include <exception>

class Bureaucrat
{
	protected:
		std::string const	_name;
		int					_grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
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
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat& other);

#endif