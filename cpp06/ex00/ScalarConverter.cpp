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

std::string check_input(std::string input)
{
	if (input == "nanf" || input == "nan" || input == "-inff")
		return ("invalid");
	else if (input == "+inff" || input == "+inf" || input == "-inff")
		return ("invalid");
	return("ok");
}

std::string check_type(const std::string& input)
{
	std::istringstream iss(input);
	double value;
	char remaining;

	if (!(iss >> value).fail() && iss.get(remaining).eof())
	{
		if (value == static_cast<int>(value))
			return ("int");
		else
		{
			if (input.find('e') != std::string::npos || input.find('E') != std::string::npos)
				return ("double");
			else
				return ("float");
		}
	}
	else if (input.length() == 1)
		return ("char");
	else
		return ("string");
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
	char *input;
	std::string type;
	void (*f[4])(std::string) = {convertFloat, convertDouble, convertInt, convertChar};
	std::string function[4] = {"float", "double", "int", "char"};

	input = const_cast<char *>(strToconvert.c_str());
	try
	{
		check_input(input);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what();
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
