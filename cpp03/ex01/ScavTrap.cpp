#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << "ScavTrap Default constructor called\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap constructor called\n";
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

ScavTrap::~ScavTrap( void ) 
{
	std::cout << "ScavTrap Destructor called\n";
}

void	guardGate( void )
{
	std::cout << "Gate keeper mode" << std::endl;
}
