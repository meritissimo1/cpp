#include <iostream>
#include <string>
#include <fstream>

std::string	replaceString(std::fstream& file, std::string str1, std::string str2)
{
	std::string line;
	std::string	replaceLine;
	while (std::getline(file, line))
	{
		size_t	pos;
		size_t	prevPos;
		int		needle;
	
		pos = 0;
		prevPos = 0;
		needle = 0;
		while ((pos = line.find(str1, pos)) != std::string::npos)
		{
			replaceLine += line.substr(prevPos, pos - prevPos);
			replaceLine += str2;
			pos += str1.length();
			prevPos = pos;
			needle++;
		}
		replaceLine += line.substr(prevPos);
		replaceLine += '\n';
		if (!needle)
			return ("NULL");
	}
	return (replaceLine);
}

int	main(int ac, char **av)
{
	std::string	outputFile;
	int	index;

	index = 0;
	if (ac - 1 != 3)
	{
		std::cout << "usage: ./replace [FILE] [str_tobe_replaced] [str_that_replace]" << std::endl;
		return(0);
	}
	std::fstream ifs(av[1]);
	if (ifs.fail())
	{
		std::cout << "error: File not found" << std::endl;
		return (0);
	}
	std::string replaced = replaceString(ifs, av[2], av[3]);
	if (replaced == "NULL")
	{
		ifs.close();
		std::cout << "error: No match" << std::endl;
		return (0);
	}
	outputFile = av[1];
	index = outputFile.find('.', index);
	if (index > 0)
		outputFile = outputFile.substr(0, index);
	outputFile +=  ".replace";
	std::ofstream ofs(outputFile.c_str());
	ofs << replaced;
	ifs.close();
	return (0);
}


