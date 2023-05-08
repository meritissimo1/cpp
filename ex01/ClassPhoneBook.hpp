#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H

# include <iostream>
# include <string.h>
# include <iomanip>

class PhoneBook {

public:
	
	char	contacts[8];	
	int i;
	PhoneBook( void );
	~PhoneBook( void );

	void bar( void );
};

#endif
