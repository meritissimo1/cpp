#ifndef CLASS_CONTACT_H
# define CLASS_CONTACT_H

# include "PhoneBook.hpp"

class Contact
{

private:
	std::string Name;
	std::string	LastName;
	std::string	NickName;
	std::string	DarkSecret;
	std::string	PhoneNumber;	
		
	public:
	
	void setName(std::string name);
	std::string getName();

	void setLastName(std::string name);
	std::string getLastName();

	void setNickName(std::string nickname);
	std::string getNickName();
	
	void setNumber(std::string phonenumber);
	std::string	getNumber();
	
	void setDarkSecret(std::string darksecret);
	std::string	getDarkSecret();

	Contact( void );
	~Contact( void );
};

#endif
