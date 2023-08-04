#include "RPN.hpp"

Rpn::Rpn( void ) {}

Rpn::Rpn(const Rpn &r)
{
	*this = r;
}

Rpn &Rpn::operator=(const Rpn &r)
{
	if (this != &r)
		this->_stack = r._stack;
	return (*this);
}

Rpn::~Rpn( void ) {}

Rpn::Rpn(std::string expression)
{
	_expression = expression;
}

static int isoperator(char op)
{
	if (op == '+' || op == '-' || op == '*' || op == '/')
		return (1);
	else
		return (0);
}

int Rpn::calcule( void )
{
	int	i;
	int result;

	i = -1;
	result = 0;
	while(_expression[++i])
	{
		if (std::isspace(_expression[i]))
			continue ;
		else if (!std::isdigit(_expression[i]) && !isoperator(_expression[i]))
			throw InvalidExpression();
		else
			std::cout << i << " - " << _expression[i] << std::endl;
	}
	return (result);
}

