#include "Animal.hpp"

Animal::Animal( void ) : _type("Dragão") 
{
	std::cout << "Animal Default constructor called\n";
}

Animal::Animal(const Animal &a)
{
	std::cout << "Animal Copy constructor called\n";
	*this = a;
}

Animal	&Animal::operator=(const Animal &a)
{
	std::cout << "Animal Copy Assignment operator called\n";
	if (this != &a)
		this->_type = a.getType();
	return (*this);
}

Animal::~Animal( void )
{
	std::cout << "Animal Destructor called\n";
}

void	Animal::makeSound( void ) const
{
	std::cout << "Animal Sound\n";
}

std::string	Animal::getType( void ) const
{
	return (this->_type);
}

void	Animal::setType(std::string type) 
{
	this->_type = type;
}

std::ostream	&operator<<(std::ostream &o, const Animal &a)
{
	o << "Type: " << a.getType() << std::endl;
	return(o);
}