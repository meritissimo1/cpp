#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	
	Bureaucrat	juarez("nunes", 137);
	PresidentialPardonForm form("galileu");

	try
	{
		juarez.signForm(form);
		//std::cout << form.getIsSigned() << std::endl;
		juarez.executeForm(form);
	}
	catch(const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
