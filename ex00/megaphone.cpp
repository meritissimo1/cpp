#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
	int i;
	int j;
	char c;
	
	i = 1;
	j = 0;	
	if ((argc - 1) == 0)
		std::cout << "* LOUD AND UNBEAREBLE FEEDBACK NOISE *";
	else
	{
		while (argv[i])
		{	
			j = 0;
			while (argv[i][j])
			{
				c = argv[i][j];
				if (argv[i][j] >= 'a' && argv[i][j] <= 'z')
				c -= 32;
				std::cout << c;
				j++;
			}	
			i++;
		}
	}
	std::cout << std::endl;
	return (0);
}
