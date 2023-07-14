#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat President("President", 1);
	std::cout << std::endl;
	Bureaucrat VicePresident("VicePresident", 2);
	std::cout << std::endl;
	Form law("No tax for games", 1, 2);
	std::cout << std::endl;

	std::cout << President;
	std::cout << std::endl;
	std::cout << VicePresident;
	std::cout << std::endl;
	std::cout << law;

	VicePresident.signForm(law);
	President.signForm(law);
	President.signForm(law);
	std::cout << law;
	std::cout << std::endl;
	
	return (0);
}
