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

int Rpn::calcule( void )
{
	int	i;
	int result;

	i = 0;
	result = 0;
	while(_expression[i])
	{
		std::cout << i << " - " << _expression[i] << std::endl;
		i++;
	}
	return (result);
}

