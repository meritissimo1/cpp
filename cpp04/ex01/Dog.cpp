#include "Dog.hpp"

Dog::Dog( void ) : Animal()
{
	std::cout << "Dog Default constructor called\n";
	this->_type = "Dog";
	_brain = new Brain();
}

Dog::Dog(const Dog &c) : Animal()
{
	std::cout << "Dog Copy constructor called\n";
	*this = c;
}

Dog	&Dog::operator=(const Dog &c)
{
	std::cout << "Dog Copy Assignment operator called\n";
	if (this != &c)
		this->_type = c.getType();
	return (*this);
}

Dog::~Dog( void )
{
	std::cout << "Dog Destructor called\n";
	delete _brain;
}

void	Dog::makeSound( void ) const
{
	std::cout << "AuAu\n";
}

std::ostream	&operator<<(std::ostream &o, const Dog &c)
{
	o << "Type: " << c.getType() << std::endl;
	return(o);
}

