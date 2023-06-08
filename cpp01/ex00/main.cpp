#include "Zombie.hpp"

int main(void)
{
	Zombie	*newzombie;
	randomChump("john");
	newzombie = newZombie("mi");
	newzombie->announce();
	delete newzombie;
	return (0);
}
