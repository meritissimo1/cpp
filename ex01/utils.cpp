#include "ClassPhoneBook.hpp"
#include <string>

void	menu( void )
{
	std::cout << std::left << std::setfill('.') << std::setw(12);
	std::cout << "ADD" << "Save a new contact" << std::endl;
	std::cout << std::left << std::setfill('.') << std::setw(12);
	std::cout << "SEARCH" << "Display a specific contact" << std::endl;
	std::cout << std::left << std::setfill('.') << std::setw(12);
	std::cout << "EXIT" << "Close the program" << std::endl;
}

void	add( void )
{
	std::string	Name;
	Contact		contact;	

	std::cout << "Name: ";	
	std::getline (std::cin, Name);
	std::cout << Name << std::endl;
//	std::cin >> Name;
//	std::cout << contact.getName() << std::endl;
//	contact.setName(Name);
}

void	input_user(std::string buffer)
{
	if (buffer == "ADD")
		add();
	else if (buffer == "SEARCH")
		std::cout << "SEARCH" << std::endl;
}
