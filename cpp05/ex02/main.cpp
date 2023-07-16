#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	try
	{
		Bureaucrat office("Michael Scott", 200);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	Bureaucrat office("Michael Scott", 150);
	try
	{
		office.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat officer("Michael Scott", -2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	Bureaucrat nunes("nunes", 136);
	ShrubberyCreationForm strawberry("aimee");
	
	nunes.executeForm(strawberry);
	nunes.signForm(strawberry);
	nunes.executeForm(strawberry);
	nunes.signForm(strawberry);
	
	RobotomyRequestForm robot("elliot");
	Bureaucrat mm("meritissimo1", 44);
	
	mm.executeForm(robot);
	mm.signForm(robot);
	nunes.executeForm(robot);
	mm.executeForm(robot);

	PresidentialPardonForm lucas("lucas");
	Bureaucrat lade("lade", 4);
	
	lade.signForm(lucas);
	lade.executeForm(lucas);

	return (0);
}
