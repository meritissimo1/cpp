#include "easyfind.hpp"

int main ( void )
{
	std::list<int>	list1;

	list1.push_back(42);
	list1.push_back(37);  
	list1.push_back(10);  
	list1.push_back(-1);  
	list1.push_back(5);  
	
	try
	{
		::easyfind(list1, 42);
		::easyfind(list1, 37);
		::easyfind(list1, 10);
		::easyfind(list1, -1);
		::easyfind(list1, 5);
		::easyfind(list1, 9);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what();
	}

	return (0);
}

