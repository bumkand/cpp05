#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"


class Form : public Bureaucrat
{
    private:
        const std::string   _name;
        bool                _signed;
        const int           _signGrade;
        const int           _exeGrade;
    
    public:
        Form();
        Form()
    
        const std::string getName(void) const;
        const int getSignGrade(void) const;
        const int getExeGrade(void) const;

        void beSigned(Bureaucrat*);

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