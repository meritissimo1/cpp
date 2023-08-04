#include "RPN.hpp"

	Rpn::Rpn( void ) : _result(0) {}

Rpn::Rpn(const Rpn &r)
{
	*this = r;
}

Rpn &Rpn::operator=(const Rpn &r)
{
	if (this != &r)
	{
		this->_stack = r._stack;
		this->_expression = r._expression;
		this->_result = r._result;
	}
	return (*this);
}

Rpn::~Rpn( void ) {}

Rpn::Rpn(std::string expression)
{
	_expression = expression;
	_result = 0;
}

static int isoperator(int c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (1);
	else
		return (0);
}


static int checkInvalidStack(std::stack<int> stack)
{
	if (stack.empty())
		return (1);
	return (0);
}

void Rpn::multiply( void )
{
	int x;
	int y;
	x = _stack.top();
	_stack.pop();
	y = _stack.top();
	_stack.pop();
	std::cout << x << " * " << y << std::endl; 
}

void Rpn::divide( void )
{
	std::cout << "divide em obras\n";
}

void Rpn::sum( void )
{
	std::cout << "sum em obras\n";
}

void Rpn::subtract( void )
{
	std::cout << "sub em obras\n";
}

void	Rpn::DoExpression(char arithmetic)
{
	if (checkInvalidStack(_stack))
		throw InvalidExpression();	
	else if (arithmetic == '*')
		multiply();
	else if (arithmetic == '/')
		divide();
	else if (arithmetic == '+')
		sum();
	else if (arithmetic == '-')
		subtract();
}


void Rpn::insertOnStack(char number)
{
	int n = number - '0';
	_stack.push(n);
}

int Rpn::calcule( void )
{
	int	i;

	i = -1;
	while(_expression[++i])
	{
		if (std::isspace(_expression[i]))
			continue ;
		else if (!std::isdigit(_expression[i]) && !isoperator(_expression[i]))
			throw InvalidExpression();
		else if (isoperator(_expression[i]))
			DoExpression(_expression[i]);
		else
			insertOnStack(_expression[i]);
	}
	while(!_stack.empty())
	{
		std::cout << _stack.top() << std::endl;
		_stack.pop();
	}
	return (_result);
}

