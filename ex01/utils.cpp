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

void	add( void )
{
	std::string	Name;
	Contact		contact;	

	std::cout << "Insert your name: ";	
	std::cin >> Name;
	// std::getline(std::cin, Name);
	contact.setName(Name);	
	std::cout << contact.getName() << std::endl;
}

void	input_user(char *buffer)
{
	if (!strcmp(buffer, "ADD"))
		add();
	else if (!strcmp(buffer, "SEARCH"))
		std::cout << "SEARCH" << std::endl;
}
