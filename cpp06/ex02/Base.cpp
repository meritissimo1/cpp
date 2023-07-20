#include "Base.hpp"

Base::~Base ( void )
{
	std::cout << "Destructor called\n";
}

Base *generate(void)
{
	int random;
    std::srand(static_cast<unsigned>(std::time(0)));
	random = std::rand() % 3;
	switch (random)
	{
		case 0:
			return new A();
			break;
		case 1:
			return new B();
			break;
		case 2:
			return new C();
			break;
	}
	return (NULL);
}

void identify(Base *p)
{
	std::cout << "type: ";
	if (dynamic_cast<A *>(p))
		std::cout << "(pointer) A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "(pointer) B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "(pointer) C" << std::endl;
	else
		std::cout << "None" << std::endl;
}

void identify(Base &p)
{
	std::cout << "type: ";
	if (dynamic_cast<A*>(&p) != NULL)
		std::cout << "(reference) A" << std::endl;
	else if (dynamic_cast<B*>(&p) != NULL)
		std::cout << "(reference) B" << std::endl;
	else if (dynamic_cast<C*>(&p) != NULL)
		std::cout << "(reference) C" << std::endl;
	else
		std::cout << "None" << std::endl;
}

