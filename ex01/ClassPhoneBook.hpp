#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H

# include <iostream>
# include <string.h>
# include <iomanip>
# include "ClassContact.hpp"

class PhoneBook {	

public:
	
	Contact contacts[8];
	int		NumberOfContacts;
	PhoneBook( void );
	~PhoneBook( void );

};

void	menu( void );
void	input_user(std::string buffer, PhoneBook *list);

#endif
