#include "ClassPhoneBook.hpp"

void	Add(PhoneBook *list)
{
	int			i;

	if (list->NumberOfContacts == 8)
		list->NumberOfContacts = 0;
	i = list->NumberOfContacts;
	Name(list->contacts[i]);
	NickName(list->contacts[i]);
	PhoneNumber(list->contacts[i]);
	DarkSecret(list->contacts[i]);
	list->NumberOfContacts++;
}

void	Search(std::string	buffer, PhoneBook *list)
{
	std::string	ContactId;
	int			i;

	(void)buffer;
	std::cout << "Insert the index: ";
	std::getline(std::cin, ContactId);
	i = std::stoi(ContactId);
	if (i >= 0 && i <= 7)
		std::cout << list->contacts[0].getName() << std::endl; 		
	else
		std::cout << "errado" << std::endl;	
}
