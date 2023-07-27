#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <list>
# include <algorithm>

class Span
{
	public:
		Span( void );
		Span(unsigned int N);
		Span(const Span &s);
		Span &operator=(const Span &s);
		~Span( void );

		void addNumber();
		void addNumber(); // add more than one number
		

		void shortestSpan( void );
		void longestSpan( void );

		unsigned int getNumber( void );
		void setNumber(unsigned int N);

	private:
		unsigned int N; 
};

#endif

