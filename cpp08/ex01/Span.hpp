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

		void addNumber(unsigned int n);
		void addNumber( void ); // add more than one number
		

		int	shortestSpan( void );
		int	longestSpan( void );

		unsigned int getNumber( void );
		void setNumber(unsigned int N);

		class IndexOutBounds : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return ("Index out bounds\n");
				}			
		};

	private:
		unsigned int 	N; 
		size_t			size;
		std::list<int>	containerInt; 
};

template <typename T>
void printc(T &container);

#endif

