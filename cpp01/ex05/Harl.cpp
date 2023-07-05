#include "Harl.hpp"

Harl::Harl(void) {}

Harl::~Harl(void) {}

void	Harl::debug(void)
{
	std::cout << "--Debug--" << std::endl;
}

void	Harl::info(void) 
{
	std::cout << "--Info--" << std::endl;
}

void	Harl::warning(void) 
{
	std::cout << "--Warning--" << std::endl;
}

void	Harl::error(void) 
{
	std::cout << "--Error--" << std::endl;
}

void	Harl::complain(std::string level)
{
	void (Harl::*f[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string entryFunctions[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};	
	int i;

	i = 0;
	while (i <= 3)
	{
		if (level == entryFunctions[i])
		{	
			(this->*f[i])();
			return;
		}
		i++;
	}
	if (i == 4)
		std::cout << "error: Not match" << std::endl;
}
