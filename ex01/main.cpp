#include "ClassPhoneBook.hpp"

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
		input_user(buffer);
	}	 
	return (0);
}
