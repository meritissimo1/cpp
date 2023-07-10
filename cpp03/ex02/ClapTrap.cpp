#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("<<Lucas"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap Default constructor called\n";
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &cp)
{
	*this = cp;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &cp)
{
	if (this != &cp)
	{
		this->_name = cp.getName();
		this->_hitPoints = cp.getHit();
		this->_attackDamage = cp.getAttack();
		this->_energyPoints = cp.getEnergy();
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &o, const ClapTrap &Obj)
{
	o << "Name: "<< Obj.getName() << std::endl;
	o << "Attack damage: " << Obj.getAttack() << std::endl;
	o << "Energy Points: "<< Obj.getEnergy() << std::endl;
	o << "Hit Points: " << Obj.getHit() << std::endl;
	return (o);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap Destructor called" << std::endl;
	return ;
}

std::string	ClapTrap::getName(void) const
{
	return (this->_name);
}

void	ClapTrap::setName(std::string const name)
{
	this->_name = name;
}

int	ClapTrap::getHit(void) const
{
	return (this->_hitPoints);
}

void	ClapTrap::setHit(int const hitPoints)
{
	this->_hitPoints = hitPoints;
}

int ClapTrap::getEnergy(void) const
{
	return (this->_energyPoints);
}

void	ClapTrap::setEnergy(int const energyPoints)
{
	this->_energyPoints = energyPoints;
}

int	ClapTrap::getAttack(void) const
{
	return (this->_attackDamage);
}

void	ClapTrap::setAttack(int const attackDamage)
{
	this->_attackDamage = attackDamage;
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << this->_name << " is dead" << std::endl;
		return ;
	}
	else if (this->_energyPoints <= 0)
		std::cout << this->_name << " Without energy points" << std::endl;
	else
	{
		this->_energyPoints--;
		std::cout << "ClapTrap " << this->getName() << " attacks " << target 
		<< " causing " << this->_attackDamage  << " points of damage" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints <= 0)
		std::cout << "ClapTrap " << this->_name << "is already dead.\n";
	else
	{
		this->_hitPoints -= amount;
		std::cout << "ClapTrap " << this->_name << " -" << amount << "Hit" 
		<< std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints <= 0)
		std::cout << "You are without Energy point" << std::endl;
	else if (this->_hitPoints <= 0)
		std::cout << "You can't repair, because you are dead\n";
	else
	{
		this->_energyPoints--;
		this->_hitPoints += amount;
		std::cout << "ClapTrap " << this->_name << " +" << amount << " Hit"
		<< std::endl;
	}
}
