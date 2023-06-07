#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	phonebook;
	std::string	buffer;

	while (1)
	{
		menu();
		std::getline(std::cin, buffer);
		if (buffer == "EXIT" && Exit())
			return (0);
		input_user(buffer, &phonebook);
	}	 
	return (0);
}
