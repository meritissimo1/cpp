#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>
# include <cctype>
# include <iterator>
# include <algorithm>

class Rpn
{
	public:
		Rpn( void );
		Rpn(std::string expression);
		Rpn(const Rpn &r);
		Rpn &operator=(const Rpn &r);
		~Rpn( void );
	
		int calcule( void );

	class InvalidExpression : public std::exception
	{
		public:
			const char *what() const throw()
			{
				return ("Error: Invalid Expression\n");
			}
	};

	private:
		std::string _expression;
		std::stack<int> _stack;
};

#endif
