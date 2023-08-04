#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: " << av[0] << " [Expression]" << std::endl;
		return (0);
	}

	try
	{
		int result;
	
		Rpn rpn(av[1]);
		result = rpn.calcule();
		std::cout << result << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what();
	}
	return (0);
}