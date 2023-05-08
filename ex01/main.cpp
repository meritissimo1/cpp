#include "ClassPhoneBook.hpp"

void	menu( void )
{
	std::cout << std::left << std::setfill('.') << std::setw(12);
	std::cout << "ADD" << "Save a new contact" << std::endl;
	std::cout << std::left << std::setfill('.') << std::setw(12);
	std::cout << "SEARCH" << "Display a specific contact" << std::endl;
	std::cout << std::left << std::setfill('.') << std::setw(12);
	std::cout << "EXIT" << "Close the program" << std::endl;
}


int	main()
{
	PhoneBook	instance;
	
	char	buffer[42];

	while (1)
	{
		menu();
		std::cin >> buffer;
		if (!strcmp(buffer, "EXIT"))
		{
			char	decision;
			std::cout << "All the contacts will lost, are you sure about that? [Y/N]";
			std::cin >> decision;
			if (decision == 'y' || decision == 'Y')
			{
				std::cout  << "B" << decision << "e" << std::endl;
				return (0);
			}
		}
	}	 
	return (0);
}
