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

void	Span::addNumber(unsigned int n)
{
	if (this->size >= this->N)
		throw IndexOutBounds();
	this->containerInt.push_back(n);
	std::cout << "Add [" << n << "] on list\n";
	this->size++;
}

template <typename T>
void	printc(T &container)
{
	std::list<int>::iterator it;
	

	for (it = container.begin(); it != container.end(); ++it)
		std::cout << *it << " ";
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
	





