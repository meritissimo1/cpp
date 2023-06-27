#include "Zombie.hpp"

int main(void)
{
	Zombie	*newzombie;

	newzombie = newZombie("Estalador");
	randomChump("Corredor");
	newzombie->announce();
	delete newzombie;
	return (0);
}
