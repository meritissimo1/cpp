#include "HumanA.hpp"
#include "HumanB.hpp"

std::string	Weapon::getType()
{
	return (this->type);
}

void	Weapon::setType(std::string type)
{
	this->type = type;
}

void	HumanA::attack(void)
{
	std::cout << this->name << " attacks with their " << this->WeaponA.getType() << std::endl;
}

void HumanB::attack(void)
{
	std::cout << this->name << " attack with their " << this->WeaponB->getType() << std::endl;
}


Weapon::Weapon(std::string type)
{
	this->type = type;
}

Weapon::~Weapon(){
}
