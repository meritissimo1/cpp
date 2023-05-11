#ifndef CLASS_CONTACT_H
# define CLASS_CONTACT_H

class Contact
{

private:
	std::string Name;
	std::string	NickName;
	std::string	DarkSecret;
	std::string	PhoneNumber;	
		
	public:
	
	void setName(std::string name);
	std::string getName();

	void setNickName(std::string nickname);
	std::string getNickName();
	
	void setNumber(std::string phonenumber);
	std::string	getNumber();

	Contact( void );
	~Contact( void );
};

#endif
