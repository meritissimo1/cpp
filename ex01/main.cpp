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


void	input_user(char *buffer)
{
	if (!strcmp(buffer, "ADD"))
		std::cout << "ADD" << std::endl;
	else if (!strcmp(buffer, "SEARCH"))
		std::cout << "SEARCH" << std::endl;
}

int	main(int argc, char **argv)
{
	PhoneBook	instance;
	
	char	buffer[42];
	(void)argv;
	if (argc > 1)
		return (0);
	while (1)
	{
		menu();
		std::cin >> buffer;
		input_user(buffer);
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
