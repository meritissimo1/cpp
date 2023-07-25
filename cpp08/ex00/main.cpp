#include "easyfind.hpp"

void displayInt(int i)
{
	std::cout << i << std::endl;
}

int main ( void )
{
	std::list<int>	list1;

	list1.push_back(42);
	list1.push_back(37);  
	list1.push_back(10);  
	list1.push_back(-1);  
	list1.push_back(100);  
	//for_each(list1.begin(), list1.end(), displayInt); intra videos
	
	try
	{
		::easyfind(list1, 37);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what();
	}


	std::list<char>	list2;
	list2.push_back('a');
	list2.push_back('b');
	list2.push_back('i');
	list2.push_back('a');
	
	char		param;
	param = 'b';
	
	try
	{
		::easyfind(reinterpret_cast<std::list<int>(list2), static_cast<int>(param));
	}
	catch(const std::exception &e)
	{
		std::cout << e.what();
	}

	return (0);
}

