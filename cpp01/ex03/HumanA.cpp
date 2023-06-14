#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : WeaponA(weapon)
{
	this->name = name;
}

HumanA::~HumanA(){
}
