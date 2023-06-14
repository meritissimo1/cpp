#include <iostream>

int	main(void)
{
	std::string	brain;
	std::string	*stringPTR;


	brain = "HI THIS IS BRAIN";
	stringPTR = &brain;
	std::string& stringREF = brain;
	std::cout << &brain << std::endl << stringPTR << std::endl << &stringREF << std::endl;
	std::cout << brain << std::endl << *stringPTR << std::endl << stringREF << std::endl;
	return (0);
}
