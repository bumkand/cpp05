#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :
	AForm("ShrubberyCreationForm", 145, 137),
	_target("Default_target")
{
	//std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	AForm("ShrubberyCreationForm", 145, 137),
	_target(target)
{
	//std::cout << "ShrubberyCreationForm parametrized constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :
	AForm(other),
	_target(other._target)
{
	//std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

//ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
//{
//	if (this != &other)
//	{
//		_target = other._target;
//	}
//	//std::cout << "ShrubberyCreationForm assigment operator called" << std::endl;
//	return *this;
//}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	//std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

const char* ShrubberyCreationForm::FileIsClosed::what() const throw()
{
	return "File is not open";
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (getSigned() == false)
		throw AForm::DocumentNotSigned();
	if (executor.getGrade() > getExeGrade())
		throw AForm::GradeTooLowException();

	std::ofstream	file;
	file.open((_target + "_shrubbery").c_str());
	if (!file.is_open())
		throw FileIsClosed();
	
	const std::string	tree = "       *\n"
                               "      ***\n"
                               "     *****\n"
                               "    *******\n"
                               "   *********\n"
                               "      |||\n\n";
	for (int i = 0; i < 5; i++)
		file << tree;
	file.close();
}