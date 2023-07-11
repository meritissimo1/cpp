#include "Cat.hpp"

Cat::Cat( void ) : Animal() 
{
	this->_type = "Cat";
	std::cout << "Cat Default constructor called\n";
}

Cat::Cat(const Cat &c) : Animal()
{
	std::cout << "Cat Copy constructor called\n";
	*this = c;
}

Cat	&Cat::operator=(const Cat &c)
{
	std::cout << "Cat Copy Assignment operator called\n";
	if (this != &c)
		this->_type = c.getType();
	return (*this);
}

Cat::~Cat( void )
{
	std::cout << "Cat Destructor called\n";
}

void	Cat::makeSound( void ) const
{
	std::cout << "MewMew\n";
}

std::ostream	&operator<<(std::ostream &o, const Cat &c)
{
	o << "Type: " <<  c.getType() << std::endl;
	return(o);
}

