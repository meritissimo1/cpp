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
	std::list<int>	sorted;

	sorted = this->containerInt;
	sorted.sort();
	std::list<int>::iterator begin;
	std::list<int>::iterator end;
	begin = sorted.begin();
	end = sorted.end();
	--end;
	return (*end - *begin);
}
	
int Span::shortestSpan( void )
{
	std::list<int>::iterator	it;
	std::list<int>::iterator	nextIt;
	std::list<int>				sorted;
	int							shortest;
	int							minor;

	sorted = this->containerInt;
	sorted.sort();
	it = sorted.begin();
	nextIt = it++;
	shortest = abs(*it - *nextIt);
	for(; nextIt != sorted.end(); nextIt++)
	{
		minor = abs(*it - *nextIt); 
		if (minor < shortest)
			shortest = minor;
		it++;
	}
	return (shortest);
}


void	Span::addSeveralNumber(std::list<int>::iterator it, std::list<int>::iterator ite, int n)
{
	for (; it != ite; it++)
		addNumber(n);
}

