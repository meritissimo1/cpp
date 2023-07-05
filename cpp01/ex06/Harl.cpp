#include "Harl.hpp"

Harl::Harl(void) {}

Harl::~Harl(void) {}

void	Harl::debug(void)
{
	std::cout << "debug" << std::endl;
}

void	Harl::info(void) 
{
	std::cout << "info" << std::endl;
}

void	Harl::warning(void) 
{
	std::cout << "warning" << std::endl;
}

void	Harl::error(void) 
{
	std::cout << "error" << std::endl;
}

void	Harl::complain(std::string level)
{
	int	value;
	int	i;

<<<<<<< HEAD
	value = 0;
=======
	value = 4;
>>>>>>> 2cad22e9b4a7bdca2cdf01d9329147d0da0976fd
	static const  enumMap levels[] = {
		{"DEBUG", DEBUG},
		{"INFO", INFO},
		{"WARNING", WARNING},
		{"ERROR", ERROR}
	};
	for (i = 0; i < TOTAL; i++)
	{
		if (level == levels[i].level)
		{
			value = levels[i].value;
			break;
		}
	}
<<<<<<< HEAD
	if (i < 4)
	{
		switch(value)
		{
			case DEBUG:
				this->debug();
			case INFO:
				this->info();
			case WARNING:
				this->warning();
			case ERROR:
				this->error();
		}
	
	}
	else
		std::cout << "error: Not match" << std::endl;
=======
	switch(value)
	{
		case DEBUG:
			this->debug();
		case INFO:
			this->info();
		case WARNING:
			this->warning();
		case ERROR:
			this->error();
			break;
		default:
			std::cout << "error: Not match" << std::endl;
	}	
>>>>>>> 2cad22e9b4a7bdca2cdf01d9329147d0da0976fd
}

