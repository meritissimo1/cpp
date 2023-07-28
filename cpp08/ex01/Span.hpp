#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <list>
# include <algorithm>
# include <iterator>

class Span
{
	public:
		Span( void );
		Span(unsigned int N);
		Span(const Span &s);
		Span &operator=(const Span &s);
		~Span( void );

		void addNumber(unsigned int n);
		void addSeveralNumber(std::list<int>::iterator it, std::list<int>::iterator ite, int n); // add more than one number
		

		int	shortestSpan( void );
		int	longestSpan( void );

		unsigned int getNumber( void );
		void setNumber(unsigned int N);
		template <typename T>
		T &getContainer(void);

		class IndexOutBounds : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return ("Index out bounds\n");
				}			
		};


		void printc( void )
		{
			std::list<int>::iterator it;
			for (it = this->containerInt.begin(); it != this->containerInt.end(); ++it)
			std::cout << *it << " ";
		}

	private:
		unsigned int 	N; 
		size_t			size;
		std::list<int>	containerInt; 
};


#endif

