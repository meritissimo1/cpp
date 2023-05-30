#include "PhoneBook.hpp"

Contact::Contact( void ){
}

Contact::~Contact( void ){
}

void	Contact::setName(std::string name)
{
	this->Name = name;
}

std::string	Contact::getName()
{
	return(this->Name);
}

void	Contact::setLastName(std::string lastname)
{
	this->LastName = lastname;
}

std::string	Contact::getLastName()
{
	return(this->LastName);
}

void	Contact::setNickName(std::string nickname)
{
	this->NickName = nickname;
}

std::string	Contact::getNickName()
{
	return (this->NickName);
}

void	Contact::setNumber(std::string phonenumber)
{
	this->PhoneNumber = phonenumber;
}

std::string	Contact::getNumber()
{
	return (this->PhoneNumber);
}

void	Contact::setDarkSecret(std::string darksecret)
{
	this->DarkSecret = darksecret;
}

std::string	Contact::getDarkSecret()
{
	return (this->DarkSecret);
}
