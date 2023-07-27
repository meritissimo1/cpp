#include "Span.hpp"

Span::Span( void ) : N(0);

Span::Span(unsigned int n) : N(n);

Span::Span(const Span &s)
{
	*this = s;
}

Span	&Span::operator=(const Span &s)
{
	if (this != &s)
		this->N = s.N;
	return (*this);
}

Span::~Span( void ) {}

