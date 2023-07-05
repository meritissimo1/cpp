#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed( void ) : FixedPoint(0) {}

Fixed::Fixed(const int number)
{
	this->FixedPoint = number * (1 << this->bits);
}

Fixed::Fixed(const float number)
{
	this->FixedPoint = roundf((number * (1 << this->bits)));
}

int		Fixed::toInt( void ) const
{
	return(this->FixedPoint / (1 << this->bits)); 
}

float	Fixed::toFloat( void ) const
{
	return((float)this->FixedPoint	/ (1 << this->bits));	
}

Fixed::~Fixed( void )
{
}

Fixed::Fixed(const Fixed &copyFixed)
{
	*this = copyFixed;
}

int	Fixed::getRawBits( void ) const
{
	return (this->FixedPoint);
}

void	Fixed::setRawBits(int const raw)
{
	this->FixedPoint = raw;
}

Fixed	&Fixed::operator=(const Fixed &assignmentFixed)
{
	if (this != &assignmentFixed)
		this->FixedPoint = assignmentFixed.FixedPoint;
	return (*this);
}

std::ostream &operator<<(std::ostream &o, const Fixed &Obj)
{
	o << Obj.toFloat();
	return (o);
}

float	Fixed::operator*(const Fixed &fixed) const
{
	return (float(this->toFloat() * fixed.toFloat()));
}

float	Fixed::operator+(const Fixed &fixed) const
{
	return (float(this->toFloat() + fixed.toFloat()));
}

float	Fixed::operator-(const Fixed &fixed) const
{
	return ((this->toFloat() - fixed.toFloat()));
}

float	Fixed::operator/(const Fixed &fixed) const
{
	return ((this->toFloat() / fixed.toFloat()));	
}

bool	Fixed::operator==(const Fixed &fixed) const
{
	return ((this->toFloat() == fixed.toFloat()));
}

Fixed	&Fixed::operator++(void)
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed aux;

	aux = *this;
	this->setRawBits(this->getRawBits() + 1);
	return (aux);
}

Fixed	&Fixed::operator--(void)
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);	
}

Fixed	Fixed::operator--(int)
{
	Fixed aux;

	aux = *this;
	this->setRawBits(this->getRawBits() - 1);
	return (aux);
}

bool	Fixed::operator>(const Fixed &fixed) const
{
	return ((this->toFloat() > fixed.toFloat()));
}

bool	Fixed::operator<(const Fixed &fixed) const
{
	return ((this->toFloat() < fixed.toFloat()));
}

bool	Fixed::operator>=(const Fixed &fixed) const
{
	return ((this->toFloat() >= fixed.toFloat()));	
}

bool	Fixed::operator<=(const Fixed &fixed) const
{
	return ((this->toFloat() <= fixed.toFloat()));
}

bool	Fixed::operator!=(const Fixed &fixed) const
{
	return ((this->toFloat() != fixed.toFloat()));
}
