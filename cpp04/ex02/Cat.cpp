#include "Cat.hpp"

Cat::Cat( void ) : AAnimal() 
{
	this->_type = "Cat";
	std::cout << "Cat Default constructor called\n";
	this->_brain = new Brain();
}

Cat::Cat(const Cat &c) : AAnimal()
{
	std::cout << "Cat Copy constructor called\n";
	this->_brain = new Brain();
	*this = c;
}

Cat	&Cat::operator=(const Cat &c)
{
	std::cout << "Cat Copy Assignment operator called\n";
	if (this != &c)
	{
		this->_type = c.getType();
		*this->_brain = *c._brain;
	}
	return (*this);
}

Cat::~Cat( void )
{
	std::cout << "Cat Destructor called\n";
	delete _brain;
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

