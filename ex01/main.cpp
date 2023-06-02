#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	phonebook;
	std::string	buffer;

	while (1)
	{
		menu();
		std::getline(std::cin, buffer);
		if (buffer == "EXIT")
		{
			std::string	decision;
			std::cout << "All the contacts will lost, are you sure about that? [y/n]";
			std::getline(std::cin, decision);
			if (decision[0] == 'y' || decision[0] == 'Y')
			{
				std::cout << "B" << decision[0] << "e" << std::endl;
				return (0);
			}
		}
		input_user(buffer, &phonebook);
	}	 
	return (0);
}
