#include "Span.hpp"

int main(void)
{

	try
	{
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout << e.what();
	}
	
	std::cout << std::endl;
	try
	{
		Span span(5);
		
		span.addNumber(42);
		span.addNumber(24);
		span.addNumber(10);
		span.addNumber(20);
		span.addNumber(1024);
		
		int longest = span.longestSpan();
		std::cout << "[" << longest << "] is the longestSpan\n";  
		
		int shortest = span.shortestSpan();
		std::cout << "[" << shortest << "] is the shortestSpan\n";  
		
		Span span1(100001);
		for (int i = 0; i < 100001; i++)
			span1.addNumber(i);
		//span1.printc();
		std::cout << std::endl;
		
		longest = span1.longestSpan();
		std::cout << "[" << longest << "] is the longestSpan\n";  
		
		shortest = span1.shortestSpan();
		std::cout << "[" << shortest << "] is the shortestSpan\n";  
		
		std::list<int> list;
		Span johna(10);
		for (int n = 0; n < 10; n++)
			list.push_back(0);
		johna.addSeveralNumber(list.begin(), list.end(), 2);
		std::cout << std::endl;
		johna.printc();
		std::cout << std::endl;

	}
	catch(const std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	try
	{
		Span andrey(3);
	
		andrey.addNumber(1);
		andrey.addNumber(2);
		andrey.addNumber(3);
		andrey.addNumber(4);
	}
	catch(const std::exception &e)
	{
		std::cout << e.what();
	}
	return (0);
}
