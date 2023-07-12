#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : _type("WrongAnimal")
{
	std::cout << "WrongAnimal Default constructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &wa)
{
	std::cout << "WrongAnimal Constructor called\n";
	*this = wa;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &wa)
{
	std::cout << "WrongAnimal Copy Assignment operator called\n";
	if (this != &wa)
		_type = wa.getType();
	return (*this);
}

WrongAnimal::~WrongAnimal( void )
{
	std::cout << "WrongAnimal destructor called\n";
}

std::string WrongAnimal::getType(void) const
{
	return (this->_type);
}

void	WrongAnimal::setType(std::string type)
{
	this->_type = type;
}

void	WrongAnimal::makeSound( void ) const
{
	std::cout << "WrongAnimal sound\n";
}