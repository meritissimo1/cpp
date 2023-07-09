#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ScavTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(const ClapTrap &ct);
		FragTrap(const FragTrap &ft);
		FragTrap &operator=(const FragTrap &ft);
		~FragTrap( void );

		void highFivesGuys(void);
};

std::ostream	&operator<<(std::ostream &o, const FragTrap &ft);

#endif