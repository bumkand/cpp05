#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>
//#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string   _name;
        bool                _signed;
        const int           _signGrade;
        const int           _exeGrade;
    
    public:
        AForm();
        AForm(std::string name, int signgrade, int exegrade);
		AForm(const AForm& other);
		virtual ~AForm();

    
        const std::string getName(void) const;
		bool getSigned(void) const;
        int getSignGrade(void) const;
        int getExeGrade(void) const;

        void beSigned(const Bureaucrat &bureaucrat);

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

		virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream& out, const AForm& other);


#endif