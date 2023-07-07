#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap	a("celo");
	ClapTrap	b("lucas");

	a.attack(b.getName());
	b.takeDamage(a.getAttack());
		
	return (0);
}
