#include "Harl.hpp"

Harl::Harl(void) {}

Harl::~Harl(void) {}

void	Harl::debug(void)
{
	std::cout << "debug" << std::endl;
}

void	Harl::info(void) {}

void	Harl::warning(void) {}

void	Harl::error(void) {}

void	Harl::complain(std::string level)
{
	int	c = level[0];
	c %= 10;

	switch(1)
	{
		case 1:
			this->debug();
			break;
		case 2:
			this->info();
			break;
		case 3:
			this->warning();
			break;
		case 4:
			this->error();
			break;
		default:
			std::cout << "error: operator is doesn't match any case constant" << std::endl;
			break;
	}
}
