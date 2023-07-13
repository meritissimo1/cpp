#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat gui("guri", 2);

	std::cout << gui;
	try
	{
		gui.incrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << gui;
	try
	{
		gui.incrementGrade();
	}
	catch(const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << gui;
	return (0);
}
