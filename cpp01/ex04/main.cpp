#include <iostream>
#include <string>
#include <fstream>

std::string	replaceString(std::fstream& file, std::string str1, std::string str2)
{
	std::string line;
	std::string	replaceLine;
	while (std::getline(file, line))
	{
		size_t pos;
		size_t prevPos;
	
		pos = 0;
		prevPos = 0;
		while ((pos = line.find(str1, pos)) != std::string::npos)
		{
			replaceLine += line.substr(prevPos, pos - prevPos);
			replaceLine += str2;
			pos += str1.length();
			prevPos = pos;
		}
		replaceLine += line.substr(prevPos);
		replaceLine += '\n';
	}
	return (replaceLine);
}

int	main(int ac, char **av)
{
	if (ac - 1 != 3)
		return(0);
	std::fstream ifs("FaZe");
	if (ifs.fail())
		return (0);
	std::string replaced = replaceString(ifs, av[2], av[3]);
	ifs.close();
	return (0);
}


