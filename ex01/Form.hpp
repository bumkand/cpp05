#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
//#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string   _name;
        bool                _signed;
        const int           _signGrade;
        const int           _exeGrade;
    
    public:
        Form();
        Form(std::string name, int signgrade, int exegrade);
		Form(const Form& other);
		~Form();

    
        const std::string getName(void) const;
		bool getSigned(void) const;
        int getSignGrade(void) const;
        int getExeGrade(void) const;

        void beSigned(const Bureaucrat &bureaucrat);

        class GradeTooHighException : std::exception
        {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : std::exception
        {
            public:
                const char* what() const throw();
        };

};

std::ostream& operator<<(std::ostream& out, const Form& other);


#endif