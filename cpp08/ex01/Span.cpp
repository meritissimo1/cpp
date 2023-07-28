#include "Span.hpp"

Span::Span( void ) : N(0), size(0) {};

Span::Span(unsigned int n) : N(n), size(0) {};

Span::Span(const Span &s)
{
	*this = s;
}

Span	&Span::operator=(const Span &s)
{
	if (this != &s)
	{
		this->N = s.N;
		this->size = s.size;
		this->containerInt = s.containerInt;
	}
	return (*this);
}

Span::~Span( void ) {}

unsigned int Span::getNumber( void )
{
	return (this->N);
}

void	Span::setNumber(unsigned int n)
{
	this->N = n;
}

void	Span::addNumber(unsigned int n)
{
	if (this->size >= this->N)
		throw IndexOutBounds();
	this->containerInt.push_back(n);
//	std::cout << "Add [" << n << "] on list\n";
	this->size++;
}

int	Span::longestSpan( void )
{
	this->containerInt.sort();
	std::list<int>::iterator begin;
	std::list<int>::iterator end;
	begin = this->containerInt.begin();
	end = this->containerInt.end();
	--end;
	return (*end - *begin);
}
	
int Span::shortestSpan( void )
{
	std::list<int>::iterator it;
	std::list<int>::iterator nextIt;
	int shortest;
	it = this->containerInt.begin();
	nextIt = it++;
	shortest = abs(*it - *nextIt);
	for(; nextIt != containerInt.end(); nextIt++)
	{
		if (abs(*it - *nextIt) < shortest)
			shortest = *it - *nextIt;
		it++;
	}
	return (shortest);
}


void	Span::addSeveralNumber(std::list<int>::iterator it, std::list<int>::iterator ite, int n)
{
	for (; it != ite; it++)
		addNumber(n);
}

