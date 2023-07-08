#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>


class ClapTrap
{
	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &cp);
		ClapTrap &operator=(const ClapTrap &cp);
		~ClapTrap( void );
		
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		
		std::string	getName(void) const;
		void		setName(std::string const name);

		int 		getHit(void) const;
		void		setHit(int const hit);

		int			getEnergy(void) const;
		void		setEnergy(int const energy);

		int			getAttack(void) const;
		void		setAttack(int const attack);



	protected:
		std::string _name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;
};

std::ostream &operator<<(std::ostream &o, const ClapTrap &Obj);


#endif
