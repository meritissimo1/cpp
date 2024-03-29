#include "PmergeMe.hpp"


int main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "Usage : " << av[0] << " [numbers]" << std::endl;
		return (0);
	}
	try
	{
		PmergeMe isa(ac, av);
		isa.sort();
		PmergeMe::Deque jujuba(ac, av);
		jujuba.Sort();
	}
	catch (const std::exception &e)
	{
		std::cout << e.what();
	}	
	
	return (0);
}
