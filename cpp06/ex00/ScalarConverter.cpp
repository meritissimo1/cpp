#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter( void )
{
	std::cout << "Default constructor called\n";
}

ScalarConverter::ScalarConverter(const ScalarConverter &sc)
{
	std::cout << "Copy constructor called\n";
	*this = sc;
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &sc)
{
	std::cout << "Copy assignmet operator called\n";
	if (this != &sc)
		*this = sc;
	return (*this);
}

ScalarConverter::~ScalarConverter( void )
{
	std::cout << "Destructor called\n";
}

int check_input(std::string input)
{
	if (input == "nanf" || input == "nan" || input == "-inff")
		return (1);
	else if (input == "+inff" || input == "+inf" || input == "-inf")
		return (1);
	else if (input.empty())
		return (1);
	return(0);
}


bool getInt(const std::string& str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (i == 0 && str[i] == '-')
            continue;
        if (!std::isdigit(static_cast<unsigned char>(str[i])))
            return false;
    }
    if (str.length() > 11 && (str[0] != '-' || str.length() > 12))
        return false;
    return true;
}

std::string check_type(const std::string& str)
{
	if (str.length() == 1 && !std::isdigit(str[0]))
		return "char";
	bool hasDigits = false;
	bool hasDot = false;
	bool hasF = false;
	size_t index = 0;

	if (str[0] == '-' || str[0] == '+')
	{
		if (str.length() == 1 || !std::isdigit(str[1]))
			return "Invalid input";
		index = 1;
	}
	for (; index < str.length(); index++)
	{
		if (std::isdigit(str[index]))
		{
			hasDigits = true;
			continue;
		}
		else if (str[index] == '.' && !hasDot && index < str.length() - 1 && std::isdigit(str[index + 1]))
		{
			hasDot = true;
			continue;
		}
		else if ((str[index] == 'f' || str[index] == 'F') && !hasF && index == str.length() - 1 && hasDigits)
		{
			hasF = true;
			continue;
		}
		return "Invalid input";
	}
	if (hasF)
		return (hasDot) ? "float" : "Invalid input";
	else
	{
		if (hasDot || !hasDigits)
			return (hasDot) ? "double" : "Invalid input";
		else
		{
			long value = std::strtol(str.c_str(), NULL, 10);
			if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
				return "Invalid input";
			return "int";
		}
	}
}

void	print_invalid()
{

	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}

void	convertFloat(std::string number)
{
	std::cout << "Function to Float: "<< number << std::endl;
}

void	convertDouble(std::string number)
{
	std::cout << "Function to Double: " << number << std::endl;
}

void	convertInt(std::string number)
{
	std::cout << "Function to Int: " << number << std::endl;
}

void	convertChar(std::string number)
{
	std::cout << "Function Char: " << number << std::endl;
}


void ScalarConverter::convert(const std::string strToconvert)
{
	void (*f[4])(std::string) = {convertFloat, convertDouble, convertInt, convertChar};
	std::string function[4] = {"float", "double", "int", "char"};
	std::string type;

	if (check_input(strToconvert))
	{
		print_invalid();
		return ;
	}
	type = check_type(strToconvert);
	std::cout << "Type: "<< type << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (function[i] == type)
			f[i](type);
	}
}
