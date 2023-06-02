#include <iostream>
#include <cctype>

std::string	ft_ToUpper(std::string string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		string[i] = std::toupper(string[i]);
		i++;
	}
	return (string);
}

int main(int argc, char **argv)
{
	int 		i;
	std::string	s;	

	i = 1;
	if ((argc - 1) == 0)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	while (argv[i])
	{	
		s = ft_ToUpper(argv[i]);
		std::cout << s;
		i++;
	}
	std::cout << std::endl;
	return (0);
}
