#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << "ScavTrap Default constructor called\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap constructor called\n";
}

ScavTrap::ScavTrap(const ClapTrap &ct) : ClapTrap(ct)
{
	std::cout << "ScavTrap Copy constructor called\n";
	this->_name = ct.getName();
	this->_hitPoints = ct.getHit();
	this->_attackDamage = ct.getAttack();
	this->_energyPoints = ct.getEnergy();
}

ScavTrap::ScavTrap(const ScavTrap &st) : ClapTrap(st)
{
	std::cout << "ScavTrap Copy constructor called\n";
	*this = st;
}

ScavTrap 	&ScavTrap::operator=(const ScavTrap &st)
{
	std::cout << "ScavTrap Copy assigment operator called\n";
	if (this != &st)
	{
		this->_name = st.getName();
		this->_hitPoints = st.getHit();
		this->_attackDamage = st.getAttack();
		this->_energyPoints = st.getEnergy();
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &o, const ScavTrap &obj)
{
	o << "Name: "<< obj.getName() << std::endl;
	o << "Attack damage: " << obj.getAttack() << std::endl;
	o << "Energy Points: "<< obj.getEnergy() << std::endl;
	o << "Hit Points: " << obj.getHit() << std::endl;
	return (o);
}

ScavTrap::~ScavTrap( void ) 
{
	std::cout << "ScavTrap Destructor called\n";
}

void	ScavTrap::guardGate( void )
{
	if (_hitPoints <= 0)
		std::cout << "ScavTrap " << _name << " is dead"; 
	else
		std::cout << "ScavTrap " << _name << " is now in Gate keeper mode" 
		<< std::endl;
}
