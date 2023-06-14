#include "HumanB.hpp"

void	HumanB::setWeapon(Weapon &weapon)
{
	this->WeaponB = &weapon;
}

HumanB::HumanB(std::string name) : WeaponB(NULL)
{
	this->name = name;
}


HumanB::~HumanB(){
}



