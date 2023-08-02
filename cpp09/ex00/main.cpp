
#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		std::cout << "Usage: " << av[1] << "[file]" << std::endl;
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