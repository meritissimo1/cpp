#include "Harl.hpp"

Harl::Harl(void) {}

Harl::~Harl(void) {}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-"
"ketchup burger. I really do!" << std::endl;
}

void	Harl::info(void) 
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put"
"enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void) 
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for"
"years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void) 
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
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
