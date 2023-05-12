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

void	Name(Contact& contact)
{
	std::string name;

	std::cout << "Insert your name: ";
	std::getline(std::cin, name);
	contact.setName(name);
}

void	NickName(Contact& contact)
{
	std::string	nickname;

	std::cout << "Insert your nick: ";
	std::getline(std::cin, nickname);
	contact.setNickName(nickname);
}

void	PhoneNumber(Contact& contact)
{
	std::string	phonenumber;

	std::cout << "Insert your PhoneNumber: ";
	std::getline(std::cin, phonenumber);
	contact.setNumber(phonenumber);
}

void	DarkSecret(Contact& contact)
{
	std::string	darksecret;

	std::cout << "Insert your Dark Secret: ";
	std::getline(std::cin, darksecret);
	contact.setDarkSecret(darksecret);	
}

void	add(PhoneBook *list)
{
	int			i;

	if (list->NumberOfContacts == 8)
		list->NumberOfContacts = 0;
	i = list->NumberOfContacts;
	std::cout << i << std::endl;
	Name(list->contacts[i]);
	NickName(list->contacts[i]);
	PhoneNumber(list->contacts[i]);
	DarkSecret(list->contacts[i]);
	std::cout << list->contacts[0].getNickName() << std::endl;
	list->NumberOfContacts++;

}

void	input_user(std::string buffer, PhoneBook *list)
{
	if (buffer == "ADD")
		add(list);
	else if (buffer == "SEARCH")
		std::cout << "SEARCH" << std::endl;
	
}
