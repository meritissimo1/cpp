#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class	HumanA
{
	public:
		std::string	name;
		void attack(void);
		HumanA(std::string, Weapon &weapon);
		~HumanA();
	private:
		Weapon	&WeaponA;
};

#endif
