#include "Zombie.hpp"

Zombie*	zombieHorder(int n, std::string name)
{
	Zombie	*horder;
	int		i;

	horder = new Zombie[n];
	for (i = 0; i < n; i++)
	{	
		horder[i].setName(name);
	}
	return (horder);
}
