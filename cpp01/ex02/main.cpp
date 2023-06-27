#include <iostream>

int	main(void)
{
	std::string	brain;
	std::string	*stringPTR;
	std::string &stringREF = brain;

	brain = "HI THIS IS BRAIN";
	stringPTR = &brain;

	std::cout << "--Memory address--" << std::endl;
	std::cout << &brain << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl;

	std::cout << std::endl;
	std::cout << "--Variable value--" << std::endl;
	std::cout << brain << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;
	return (0);
}
