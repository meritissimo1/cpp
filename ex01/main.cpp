#include "ClassPhoneBook.hpp"

int	main(int argc, char **argv)
{
	PhoneBook	instance;
	std::string	buffer;

	(void)argv;
	if (argc > 1)
		return (0);
	while (1)
	{
		menu();
		std::getline(std::cin, buffer);
		if (buffer == "EXIT")
		{
			std::string	decision;
			std::cout << "All the contacts will lost, are you sure about that? [Y/N]";
			std::getline(std::cin, decision);
			if (decision[0] == 'y' || decision[0] == 'Y')
			{
				std::cout << "B" << decision[0] << "e" << std::endl;
				return (0);
			}
		}
		input_user(buffer);
	}	 
	return (0);
}
