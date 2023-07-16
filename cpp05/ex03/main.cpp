#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Intern someRandomIntern;
	Bureaucrat bureaucrat1("bureaucrat1", 150);
	Bureaucrat bureaucrat2("bureaucrat2", 5);
	AForm *rrf;
	AForm *rrf2;
	
	try
	{
		rrf = someRandomIntern.makeForm("invalid request", "fry");
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	try
	{
		rrf = someRandomIntern.makeForm("robotomy request", "fry");
		bureaucrat1.signForm(*rrf);
		bureaucrat1.executeForm(*rrf);
		std::cout << std::endl;
		delete rrf;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << std::endl;
	try
	{
		rrf2 = someRandomIntern.makeForm("presidential pardon", "rain");
		bureaucrat2.signForm(*rrf2);
		bureaucrat2.executeForm(*rrf2);
		std::cout << std::endl;
		delete rrf2;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << std::endl;
	return (0);
}
