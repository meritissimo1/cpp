#include "Intern.hpp"

Intern::Intern( void )
{
	std::cout << "Intern default constructor called\n";
}

Intern::Intern(const Intern &pp)
{
	std::cout << "Intern Copy constructor called\n";
	*this = pp;
}

Intern &Intern::operator=(const Intern &i)
{
	std::cout << "Intern Assignment operator called\n";
	if (this != &i)
		*this = i;
	return (*this);
}

Intern::~Intern( void )
{
	std::cout << "Intern destructor called\n";
}

static AForm *makeShrubberyCreationForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm *makePresidentialPardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

static AForm *makeRobotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

const char* Intern::InvalidFormException::what(void) const throw()
{
	return ("Form not found\n");
}

AForm* Intern::makeForm(std::string form, std::string target)
{
	AForm *(*f[3])(std::string) = {&makeShrubberyCreationForm, &makePresidentialPardonForm, &makeRobotomyRequestForm};
	std::string forms[3] = { "shrubbery creation", "presidential pardon", "robotomy request"};

	for (int i = 0; i < 3; i++)
	{
		if (form == forms[i])
		{
			std::cout << "Intern creates " << form << std::endl;
			return (f[i](target));
		}
	}
	throw Intern::InvalidFormException();
	return (NULL);
}
