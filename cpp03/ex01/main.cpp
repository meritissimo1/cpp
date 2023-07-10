#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap	a("meritissimo1");
	ScavTrap	b("isa");
	ScavTrap	c;

	std::cout << a << std::endl << b << std::endl << c <<  std::endl;

	std::cout << "\nRound one, Fight!\n\n";
	
	a.attack(b.getName());
	b.takeDamage(a.getAttack());
	b.beRepaired(10);
	c.attack(b.getName());
	b.takeDamage(c.getAttack());
	b.beRepaired(1);
	b.attack(c.getName());
	c.takeDamage(b.getAttack());
	c.attack()
	b.guardGate();

	std::cout << std::endl;
	std::cout << a << std::endl << b << std::endl << c <<  std::endl;
	std::cout << "Round Finished\n";
	
	return (0);
}
