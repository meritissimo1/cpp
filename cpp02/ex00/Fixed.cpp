#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed( void )
{
	std::cout << "Default constructor called" << std::endl;
	this->FixedPoint = 0;
}

Fixed::~Fixed( void ) 
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copyFixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copyFixed;
}

Fixed	&Fixed::operator=(const Fixed &assignmentFixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
		if (this != &assignmentFixed)
		this->FixedPoint = assignmentFixed.getRawBits();
	return (*this);
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->FixedPoint);
}

void	Fixed::setRawBits(int const raw)
{
	this->FixedPoint = raw;
}

