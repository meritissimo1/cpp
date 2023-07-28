#include "Span.hpp"

int main(void)
{
	Span span(5);

	try
	{
		span.addNumber(10);
		span.addNumber(22);
		span.addNumber(18);
		span.addNumber(4);
		span.addNumber(30);
		int i = span.longestSpan();
		std::cout << "[" << i << "] is the longestSpan\n";  
	}
	catch(const std::exception &e)
	{
		std::cout << e.what();
	}
	return (0);
}
