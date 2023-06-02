#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H

# include <iostream>
# include <string>
# include <iomanip>
# include "Contact.hpp"

class PhoneBook 
{	

	public:
	
		Contact contacts[8];
		int		NumberOfContacts;
		int		TotalOfContacts;
	
	PhoneBook( void );
	~PhoneBook( void );

};

void	menu( void );
void	input_user(std::string buffer, PhoneBook *list);
void	Name(Contact& contact);
void	LastName(Contact& contact);
void	NickName(Contact& contact);
void	PhoneNumber(Contact& contact);
void	DarkSecret(Contact& contact);
void	Add(PhoneBook *list);
void	Search(PhoneBook *list);

#endif
