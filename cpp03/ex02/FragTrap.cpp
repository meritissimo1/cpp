#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	_name = "Lade";
	_hitPoints = 100; 
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap Default constructor called\n";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100; 
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap constructor called\n";
}

FragTrap::FragTrap(const ClapTrap &ct) : ClapTrap(ct)
{
	
	std::cout << "FragTrap Copy constructor called\n";
	this->_name = ct.getName();
	this->_hitPoints = ct.getHit();
	this->_attackDamage = ct.getAttack();
	this->_energyPoints = ct.getEnergy();
	
}

FragTrap::FragTrap(const FragTrap &ft) : ClapTrap(ft)
{
	std::cout << "FragTrap Copy constructor called\n";
	*this = ft;
}

FragTrap 	&FragTrap::operator=(const FragTrap &ft)
{
	std::cout << "FragTrap Copy assigment operator called\n";
	if (this != &ft)
	{
		this->_name = ft.getName();
		this->_hitPoints = ft.getHit();
		this->_attackDamage = ft.getAttack();
		this->_energyPoints = ft.getEnergy();
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &o, const FragTrap &obj)
{
	o << "Name: "<< obj.getName() << std::endl;
	o << "Attack damage: " << obj.getAttack() << std::endl;
	o << "Energy Points: "<< obj.getEnergy() << std::endl;
	o << "Hit Points: " << obj.getHit() << std::endl;
	return (o);
}

FragTrap::~FragTrap( void ) 
{
	std::cout << "FragTrap Destructor called\n";
}

void	FragTrap::highFivesGuys( void )
{
	if (this->_hitPoints <= 0)
		std::cout << "FragTrap " << _name << " is dead\n";
	else
		std::cout << "FragTrap " << _name << " say:  HIGH FIVES!\n";
}
