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

void	input_user(std::string buffer, PhoneBook *list)
{
	if (buffer == "ADD")
		add(list);
	else if (buffer == "SEARCH")
		std::cout << "SEARCH" << std::endl;
	
}
