#include "FragTrap.hpp"

int main(void)
{
	ClapTrap	a("meritissimo1");
	ScavTrap	b("isa");
	ScavTrap	c(b);
	FragTrap	d("jujuba");
	FragTrap	e(d);
	FragTrap	f;


	std::cout << a << std::endl 
	<< b << std::endl 
	<< c << std::endl
	<< d << std::endl
	<< e << std::endl
	<< f << std::endl;

	std::cout << "\nRound one, Fight!\n\n";
	
	a.attack(b.getName());
	b.takeDamage(a.getAttack());
	b.beRepaired(10);
	b.attack(d.getName());
	d.takeDamage(b.getAttack());
	d.attack(a.getName());
	a.takeDamage(d.getAttack());
	a.beRepaired(1);
	e.attack(d.getName());
	d.takeDamage(e.getAttack());	
	b.guardGate();
	d.highFivesGuys();	

	std::cout << a << std::endl 
	<< b << std::endl 
	<< c << std::endl
	<< d << std::endl
	<< e << std::endl
	<< f << std::endl;
	std::cout << "Round Finished\n";
	
	return (0);
}
