#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed(const int number)
{
	std::cout << "Int constructor called" << std::endl;
	this->FixedPoint = number << this->bits;
}

Fixed::Fixed(const float number)
{
	std::cout << "Float constructor called" << std::endl;
	this->FixedPoint = number * (1 << this->bits);	
}

int	Fixed::toInt( void ) const
{
	int	integerValue;
	int scaling;

	scaling = 1 << this->FixedPoint;	
	integerValue = static_cast<int>(this->FixedPoint *  scaling);
	return (integerValue);
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
	this->FixedPoint = assignmentFixed.FixedPoint;
	return (*this);
}

