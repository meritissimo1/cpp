#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(const ScavTrap &st);
		ScavTrap(std::string name);
		ScavTrap &operator=(const ScavTrap &st);
		~ScavTrap(void);
		
		void guardGate();
};

#endif
