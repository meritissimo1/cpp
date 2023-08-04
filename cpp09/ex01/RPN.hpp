#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>
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

	private:
		std::string _expression;
		std::stack<int> _stack;
};

#endif