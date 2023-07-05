#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed( void ) : FixedPoint(0) {}

Fixed::Fixed(const int number)
{
	std::cout << "Int constructor called" << std::endl;
	this->FixedPoint = number * (1 << this->bits);
}

Fixed::Fixed(const float number)
{
	std::cout << "Float constructor called" << std::endl;
	this->FixedPoint = roundf((number * (1 << this->bits)));
}

int	Fixed::toInt( void ) const
{
	return(this->FixedPoint / (1 << this->bits)); 
}

float	Fixed::toFloat( void ) const
{
	return((float)this->FixedPoint	/ (1 << this->bits));	
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
	if (this != &assignmentFixed)
		this->FixedPoint = assignmentFixed.FixedPoint;
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

std::ostream &operator<<(std::ostream &o, const Fixed &Obj)
{
	o << Obj.toFloat();
	return (o);
}

int	Fixed::getRawBits( void ) const
{
	return (this->FixedPoint);
}

void	Fixed::setRawBits(int const raw)
{
	this->FixedPoint = raw;
}





