
#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: " << av[0] << " [file]" << std::endl;
		return (0);
	}
	try
	{
		BitcoinExchange	btc(av[1]);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what();
	}
	return (0);
}
