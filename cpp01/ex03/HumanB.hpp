#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class	HumanB
{
	public:
		std::string name;
		void attack(void);
		void setWeapon(Weapon &weapon);
		HumanB(std::string type);
		~HumanB();
	private:
		Weapon	*WeaponB;
};

#endif
