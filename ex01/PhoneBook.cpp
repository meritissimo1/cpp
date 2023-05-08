#include <iostream>
#include "ClassPhoneBook.hpp"

PhoneBook::PhoneBook( void )
{
	std::cout << "Hello Constructor" << std::endl;
	return;
}

PhoneBook::~PhoneBook( void )
{
	std::cout << "Hello Destructor" << std::endl;
	return;
}

void	PhoneBook::bar( void )
{
	std::cout << "My function member called" << std::endl;
	return;
}
