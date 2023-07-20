#include "Base.hpp"

int main( void )
{
	Base *base = generate();

	std::cout << "---------Testing A, B or C ------------" << std::endl;

	identify(*base);
	identify(base);
	delete base;

	std::cout << "--------Testing Invalid -------------" << std::endl;
	
	Base *baseError = new Base();
	Base &baseErrorRef = *new Base();
	identify(baseError);
	identify(baseErrorRef);
	delete baseError;
	delete &baseErrorRef;
	return(0);
}