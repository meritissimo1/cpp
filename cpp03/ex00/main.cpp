#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap	a("meritissimo1");
	ClapTrap	b("isa");
	ClapTrap	c(a);

	std::cout << a << std::endl << b << std::endl << c <<  std::endl;

	std::cout << "\nRound one, Fight!\n\n";
	
	a.attack(b.getName());
	b.takeDamage(a.getAttack());
	b.beRepaired(10);

	std::cout << a << std::endl << b << std::endl << c <<  std::endl;
	std::cout << "Round Finished\n";
	
	return (0);
}
