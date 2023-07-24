#include "Array.hpp"

int main( void )
{
	{
		Array<char> decod(3);
		Array<char> decod1(0);
		Array<int> cod(3);
		cod[0] = 112;
		cod[1] = 111;
		cod[2] = 111;

		for (int i = 0; i < 3; i++)
		{
			decod[i] = cod[i];
			std::cout << decod[i];
		}
		std::cout << std::endl;
		decod1 = decod;
		for (int i = 0; i < 3; i++)
			std::cout << decod1[i];
		std::cout << std::endl;
	}
	{	
		Array<int> arr(3);
		arr[0] = 42;
		arr[1] = 65;
		arr[2] = 'a';
		for (int i = 0; i < 3; i++)
			std::cout << arr[i] << std::endl;		
		try
		{
			std::cout << arr[4] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		Array<char> arr(8);
		std::string str = "FaZe Up!";
		for (size_t i = 0; i < arr.size(); i++)
		{
			arr[i] = str[i];
		}
		for (size_t i = 0; i < arr.size(); i++)
		{
			std::cout << arr[i];
		}
		std::cout << std::endl;
	}
	return 0;
}
