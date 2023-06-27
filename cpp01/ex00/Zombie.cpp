#include "Zombie.hpp"

Zombie::Zombie(void){
}

Zombie::~Zombie(void)
{
	std::cout << this->getName() << " was destroyed" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->name = name;
}

std::string	Zombie::getName()
{
	return (this->name);
}
