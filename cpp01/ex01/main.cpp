#include "Zombie.hpp"

int main(void)
{
	Zombie	*horder;
	int		i;

	horder = zombieHorder(N, "Ellie");
	for (i = 0; i < N; i++)
	{
		horder->announce();
	}
	delete [] horder;
	return (0);
}
