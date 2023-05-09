#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H

# include <iostream>
# include <string.h>
# include <iomanip>
# include "ClassContact.hpp"

class PhoneBook {	

public:
	
	Contact contacts[8];
	PhoneBook( void );
	~PhoneBook( void );

	void bar( void );
};

void	menu( void );
void	input_user(char *buffer);

#endif
