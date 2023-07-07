#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>


class ClapTrap
{
	public:
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &cp);
		ClapTrap &operator=(const ClapTrap &cp);
		~ClapTrap( void );
		
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		
		std::string	getName(void);
		void		setName(std::string name);

		int 		getHit(void);
		void		setHit(int hit);

		int			getEnergy(void);
		void		setEnergy(int energy);

		int			getAttack(void);
		void		setAttack(int attack);



	private:
		std::string _name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;
};

#endif
