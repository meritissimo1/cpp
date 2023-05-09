#include "ClassPhoneBook.hpp"

Contact::Contact( void ){
}

Contact::~Contact( void ){
}

void	Contact::setName(std::string name) {	
	this->Name = name;
}

std::string	Contact::getName() {
	return(this->Name);
}
