#include "ClassPhoneBook.hpp"

void	Add(PhoneBook *list)
{
	int			i;

	if (list->NumberOfContacts == 8)
		list->NumberOfContacts = 0;
	i = list->NumberOfContacts;
	Name(list->contacts[i]);
	LastName(list->contacts[i]);
	NickName(list->contacts[i]);
	PhoneNumber(list->contacts[i]);
	DarkSecret(list->contacts[i]);
	list->NumberOfContacts++;
}

void	ContactsSaved(PhoneBook *list)
{
	Contact	con;
	int		i;

	i = 0;
	std::cout << "|	Index|	First Name|	LastName|" << std::endl;
	while (list->contacts[i].getName() != "")
	{
		con = list->contacts[i];
		std::cout << "|" << i << "|" << con.getName() << "|" << con.getLastName() << std::endl;
		i++;
	}	
}

void	Search(std::string	buffer, PhoneBook *list) 
{
	std::string	id;
	const char *aux;
	int			i;
	
	(void)buffer;
	ContactsSaved(list);
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
			std::cout << "Contact not found.\n" << std::endl;
	}
}
