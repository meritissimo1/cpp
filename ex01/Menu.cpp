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
	std::string	id;
	const char *aux;
	int			i;
	
	(void)buffer;
	std::cout << "Insert the index: ";
	std::getline(std::cin, id);
	aux = id.c_str();
	if (isdigit(aux[0]))
	{	
		i = std::atoi(aux);
		if (i >= 0 && i <= 7)
		{
			std::cout << list->contacts[i].getName() << std::endl; 		
			std::cout << list->contacts[i].getNickName() << std::endl;
			std::cout << list->contacts[i].getNumber()	<< std::endl;
			std::cout << list->contacts[i].getDarkSecret() << std::endl;
		}
		else
			std::cout << "errado" << std::endl;
	}
}
