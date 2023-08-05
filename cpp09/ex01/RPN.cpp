#include "RPN.hpp"

	Rpn::Rpn( void ) : _size(0), _op(0) {}

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
		this->_op = r._op;
		this->_size = r._size;
	}
	return (*this);
}

Rpn::~Rpn( void ) {}

Rpn::Rpn(std::string expression)
{
	_expression = expression;
	_op = 0;
	_size = 0;
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
	if (checkInvalidStack(_stack))
		throw InvalidExpression();
	y = _stack.top();
	_stack.pop();
	_stack.push(x * y);
	_size -= 1;
}

void Rpn::divide( void )
{
	int x;
	int y;
	x = _stack.top();
	_stack.pop();
	if (checkInvalidStack(_stack))
		throw InvalidExpression();
	y = _stack.top();
	_stack.pop();
	if (x == 0)
		throw InvalidExpressionZero();
	_stack.push(y / x);
	_size -= 1;
}

void Rpn::sum( void )
{
	int x;
	int y;

	x = _stack.top();
	_stack.pop();
	if (checkInvalidStack(_stack))
		throw InvalidExpression();
	y = _stack.top();
	_stack.pop();
	_stack.push(x + y);
	_size -= 1;
}

void Rpn::subtract( void )
{
	int x;
	int y;

	x = _stack.top();
	_stack.pop();
	if (checkInvalidStack(_stack))
		throw InvalidExpression();
	y = _stack.top();
	_stack.pop();
	_stack.push(y - x);
	_size -= 1;
}

void	Rpn::DoExpression(char arithmetic)
{
	_op += 1;
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
	_size += 1;
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
	if (!_op)
		throw InvalidExpression();
	else if (_expression[i - 1] - '0' == _stack.top())
		throw InvalidExpression();
	else
		return (_stack.top());
}

