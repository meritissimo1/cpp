#include "PhoneBook.hpp"

void	menu( void )
{
	std::cout << std::endl;
	std::cout << std::left << std::setfill('.') << std::setw(12);
	std::cout << "ADD" << "Save a new contact" << std::endl;
	std::cout << std::left << std::setfill('.') << std::setw(12);
	std::cout << "SEARCH" << "Display a specific contact" << std::endl;
	std::cout << std::left << std::setfill('.') << std::setw(12);
	std::cout << "EXIT" << "Close the program" << std::endl;
}

int	Exit()
{
	std::string	decision;
	std::cout << "All the contacts will lost, are you sure about that? [y/n]";
	std::getline(std::cin, decision);
	if (decision[0] == 'y' || decision[0] == 'Y')
	{
		std::cout << "B" << decision[0] << "e" << std::endl;
		return (1);
	}
	return (0);
}


void	input_user(std::string buffer, PhoneBook *list)
{
	if (buffer == "ADD")
		Add(list);
	else if (buffer == "SEARCH")
		Search(list);

}
