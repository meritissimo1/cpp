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

void	Name(Contact contact)
{
	std::string name;

	std::cout << "Insert your name: ";
	std::getline(std::cin, name);
	contact.setName(name);		
}

void	NickName(Contact contact)
{
	std::string	nickname;

	std::cout << "Insert your nick: ";
	std::getline(std::cin, nickname);
	contact.setNickName(nickname);
}

void	PhoneNumber(Contact contact)
{
	std::string	phonenumber;

	std::cout << "Insert your PhoneNumber: ";
	std::getline(std::cin, phonenumber);
	contact.setNumber(phonenumber);
	std::cout << contact.getNumber() << std::endl;	
}

void	add( void )
{
	Contact		contact;	

	Name(contact);
	NickName(contact);
	PhoneNumber(contact);
}

void	input_user(std::string buffer)
{
	if (buffer == "ADD")
		add();
	else if (buffer == "SEARCH")
		std::cout << "SEARCH" << std::endl;
}
