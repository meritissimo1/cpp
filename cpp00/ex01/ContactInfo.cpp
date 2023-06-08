#include "PhoneBook.hpp"

void	Name(Contact& contact)

{
	std::string name;

	std::cout << "Insert your name: ";
	std::getline(std::cin, name);
	while (name.empty())
	{	
		std::cout << "Please, insert your name: ";
		std::getline(std::cin, name);
	}
	contact.setName(name);
}

void	NickName(Contact& contact)
{
	std::string	nickname;

	std::cout << "Insert your nick: ";
	std::getline(std::cin, nickname);
	while (nickname.empty())
	{
		std::cout << "Please, insert your nickname: ";
		std::getline(std::cin, nickname);
	}
	contact.setNickName(nickname);
}

void	PhoneNumber(Contact& contact)
{
	std::string	phonenumber;

	std::cout << "Insert your phone number: ";
	std::getline(std::cin, phonenumber);
	while (phonenumber.empty())
	{
		std::cout << "Please, insert your phone number: ";
		std::getline(std::cin, phonenumber);
	}
	contact.setNumber(phonenumber);
}

void	DarkSecret(Contact& contact)
{
	std::string	darksecret;

	std::cout << "Insert your Dark Secret: ";
	std::getline(std::cin, darksecret);
	while (darksecret.empty())
	{
		std::cout << "Please, insert your Dark Secret: ";
		std::getline(std::cin, darksecret);
	}
	contact.setDarkSecret(darksecret);	
}

void	LastName(Contact& contact)
{
	std::string	lastname;

	std::cout << "Insert your Last Name: ";
	std::getline(std::cin, lastname);
	while (lastname.empty())
	{
		std::cout << "Please, insert your last name: ";
		std::getline(std::cin, lastname);
	}
	contact.setLastName(lastname);
}

