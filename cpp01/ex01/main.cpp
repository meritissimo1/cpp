#include "Zombie.hpp"

int main(void)
{
	Zombie	*horder;
	int		i;

	horder = zombieHorder(N, "Ellie");
	for (i = 0; i < 4; i++)
	{
		horder->announce();
	}
	delete [] horder;
	return (0);
}
