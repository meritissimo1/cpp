#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) 
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &cp)
{
	*this = cp;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &cp)
{
	if (this != &cp)
	{
		this->_name = this->getName();
		this->_hitPoints = this->getHit();
		this->_attackDamage = this->getAttack();
		this->_energyPoints = this->getEnergy();
	}
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

std::string	ClapTrap::getName(void)
{
	return (this->_name);
}

void	ClapTrap::setName(std::string name)
{
	this->_name = name;
}

int	ClapTrap::getHit(void)
{
	return (this->_hitPoints);
}

void	ClapTrap::setHit(int hitPoints)
{
	this->_hitPoints = hitPoints;
}

int ClapTrap::getEnergy(void)
{
	return (this->_energyPoints);
}

void	ClapTrap::setEnergy(int energyPoints)
{
	this->_energyPoints = energyPoints;
}

int	ClapTrap::getAttack(void)
{
	return (this->_attackDamage);
}

void	ClapTrap::setAttack(int attackDamage)
{
	this->_attackDamage = attackDamage;
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->_energyPoints <= 0 || this->_hitPoints <= 0)
	{
		std::cout << this->_name << "is dead or without energy points" << std::endl;
		return ;
	}
	this->setEnergy(this->getEnergy() - 1);
	std::cout << "ClapTrap " << this->getName() << " attacks " << target << " causing " << this->_attackDamage  << " points of damage" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->_hitPoints -= amount;
	std::cout << "Claptrap " << this->_name << " take damage " << amount << std::endl;
}

void	ClapTrap::beRapaired(unsigned int amount)
{
	this->_hitPoint += amount;
	std::cout << "ClapTrap " << this->_name << " your health improve " << amount << std::endl;
}
