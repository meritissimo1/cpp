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

void	name(Contact contact)
{
	std::string name;

	std::cout << "Insert your name: ";
	std::getline(std::cin, name);
	contact.setName(name);		
}

void	nickname(Contact contact)
{
	std::string	nickname;

	std::cout << "Insert your nick: ";
	std::getline(std::cin, nickname);
	contact.setNickName(nickname);	
}

void	add( void )
{
	Contact		contact;	

	name(contact);
	nickname(contact);

}

void	input_user(std::string buffer)
{
	if (buffer == "ADD")
		add();
	else if (buffer == "SEARCH")
		std::cout << "SEARCH" << std::endl;
}
