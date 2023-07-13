#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal()
{
	std::cout << "WrongCat Default constructor called\n";
	this->_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &wa) : WrongAnimal(wa)
{
	std::cout << "WrongCat Constructor called\n";
	*this = wa;
}

WrongCat	&WrongCat::operator=(const WrongCat &wa)
{
	std::cout << "WrongCat Copy Assignment operator called\n";
	if (this != &wa)
		_type = wa.getType();
	return (*this);
}

WrongCat::~WrongCat( void )
{
	std::cout << "WrongCat destructor called\n";
}

void	WrongCat::makeSound( void ) const
{
	std::cout << "WrongCat sound\n";
}