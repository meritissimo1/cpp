#include "Animal.hpp"

AAnimal::AAnimal( void ) : _type("Dragão") 
{
	std::cout << "Animal Default constructor called\n";
}

AAnimal::AAnimal(const AAnimal &a)
{
	std::cout << "Animal Copy constructor called\n";
	*this = a;
}

AAnimal	&AAnimal::operator=(const AAnimal &a)
{
	std::cout << "Animal Copy Assignment operator called\n";
	if (this != &a)
		this->_type = a.getType();
	return (*this);
}

AAnimal::~AAnimal( void )
{
	std::cout << "Animal Destructor called\n";
}

std::string	AAnimal::getType( void ) const
{
	return (this->_type);
}

void	AAnimal::setType(std::string type) 
{
	this->_type = type;
}

std::ostream	&operator<<(std::ostream &o, const AAnimal &a)
{
	o << "Type: " << a.getType() << std::endl;
	return(o);
}
