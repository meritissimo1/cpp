#include "PhoneBook.hpp"

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
	list->TotalOfContacts++;
	if (list->TotalOfContacts > 8)
		list->TotalOfContacts = 8;
}

void	truncated(std::string InfoContact)
{
	int i;

	i = 0;
	if (InfoContact.length() >= 10)
	{
		while (i <= 9)
		{
			if (i == 9)
				InfoContact[i] = '.';
			std::cout << std::right << InfoContact[i];
			i++;
		}
	}
	else
	{
		std::cout << std::right << std::setfill(' ') << std::setw(10);
		std::cout << InfoContact;	
	}
	
}

void	ContactsSaved(PhoneBook *list)
{
	Contact	con;
	int		i;

	i = 0;
	std::cout << "|";
	std::cout << std::right << std::setfill(' ') << std::setw(10); 
	std::cout << "Index"; 
	std::cout << "|";
	std::cout << std::right << std::setfill(' ') << std::setw(10); 
	std::cout << "FirstName";
	std::cout << "|";
	std::cout << std::right << std::setfill(' ') << std::setw(10);
	std::cout << "LastName";
	std::cout << "|";
	std::cout << std::right << std::setfill(' ') << std::setw(10);
	std::cout << "NickName";
	std::cout << "|" << std::endl;
	while (i < list->TotalOfContacts)
	{
		con = list->contacts[i];
		std::cout << "|";
		std::cout << std::right << std::setfill(' ') << std::setw(10); 
		std::cout << i + 1;
		std::cout << "|"; 
		truncated(con.getName()); 
		std::cout << "|";
		truncated(con.getLastName());
		std::cout << "|";
		truncated(con.getNickName());
		std::cout << "|" << std::endl;
		i++;
	}	
}

void	Search(PhoneBook *list) 
{
	std::string	id;
	int			i;
	
	ContactsSaved(list);
	std::cout << std::endl;
	std::cout << "Insert the index: ";
	std::getline(std::cin, id);
	std::cout << std::endl;
	if (isdigit(id[0]) && id.length() == 1)
	{	
		i = id[0] - '0';
		if (i >= 1 && i <= 8 && i <= list->TotalOfContacts)
		{
			i -= 1;
			std::cout << "Name: " << list->contacts[i].getName() << std::endl;
			std::cout << "Last Name: " << list->contacts[i].getLastName() << std::endl;
			std::cout << "NickName: " << list->contacts[i].getNickName() << std::endl;
			std::cout << "Contact Number: " << list->contacts[i].getNumber()	<< std::endl;
			std::cout << "Dark Secret: " << list->contacts[i].getDarkSecret() << std::endl;
		}
		else
			std::cout << "Contact not found.\n" << std::endl;
	}
	else
		std::cout << "Invalid Contact." << std::endl;
}
