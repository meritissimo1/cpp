#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat gui("gui", 149);
	
	std::cout << std::endl;
	std::cout << gui;

	try
	{
		gui.decrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cout << "'" << gui.getGrade() + 1 << "' -";
		std::cout << e.what() << std::endl;
	}
	std::cout << gui;
	try
	{
		gui.decrementGrade();
	}
	catch(const std::exception &e)
	{
		std::cout << "'" << gui.getGrade() + 1 << "' - ";
		std::cout << e.what() << std::endl;
	}

	std::cout << gui;
	std::cout << std::endl;
	return (0);
}
