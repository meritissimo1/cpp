#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange( void ) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &be)
{
	*this = be;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &be)
{
	if (this != &be)
		*this = be;
	return (*this);
}

BitcoinExchange::~BitcoinExchange( void ) {}


void BitcoinExchange::createData(std::fstream &data)
{
	std::string	line;
	std::string	date;
	float		bitcoin;
	size_t pos;
	while(std::getline(data, line))
	{
		pos = line.find(",");
		date = line.substr(0, pos);
		line.erase(0, pos + 1);
		bitcoin = std::atof(line.c_str());
		line.clear();
		this->_dataCSV.insert(std::pair<std::string, float>(date, bitcoin));
	}
}

static int	checkInvalidPos(size_t pos, std::string line)
{
	if (pos == std::string::npos)
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return (1);
	}
	else
		return (0);
}

static int checkInvalidYear(int year)
{
	if (year < 2009 || year > 2023)
	{
		std::cout << "Error: invalid year => " << year << std::endl; 
		return (1);
	}
	else
		return (0);
}

bool isLeapYear(int year)
{
	if (year % 4 == 0)
	{
		if (year % 100 != 0 || year % 400 == 0)
			return true;
	}
	return false;
}

static int checkInvalidMonth(int month)
{
	if (month <= 0 || month > 12)
	{
		std::cout << "Error: invalid month => " << month << std::endl;
		return (1);
	}
	return (0);
}

static int checkInvalidDay(int year, int month, int day)
{
	if (!isLeapYear(year) && month == 2 && day > 28)
	{
		std::cout << "Error: invalid day => Leap Year " << year << "/" << month << "/" << "'" << day << "'" << std::endl;
		return (1);
	}
	else if (day <= 0 || day > (30 + ((month + month/8) % 2)))
	{
		std::cout << "Error: invalid day => " << year << "/" << month << "/" << "'" << day << "'" << std::endl;
		return (1);
	}
	return (0);
}

static int checkInvalidDate(std::string date)
{
	int		year;
	int		month;
	int		day;
	size_t	pos;
	int		i;

	i = 1;
	while ((pos = date.find('-')) != std::string::npos)
	{
		if (i == 1)
		{
			std::string y = date.substr(0, pos);
			date.erase(0, pos + 1);
			year = std::atoi(y.c_str());
			if (checkInvalidYear(year))
				return (1);
			i++;
		}
		else if (i == 2)
		{
			std::string m = date.substr(0, pos);
			date.erase(0, pos + 1);
			month = std::atoi(m.c_str());
			day = std::atoi(date.c_str());
			if (checkInvalidMonth(month))
				return(1);
			else if (checkInvalidDay(year, month, day))
				return(1);
			i++;
		}
	}
	if (pos == std::string::npos && i == 1)
	{
		std::cout << "Error: bad input => " << date << std::endl;
		return (1);
	}
	return (0);
}

static int checkInvalidCoin(_uint64 coin)
{
	if (coin < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return (1);
	}
	if (static_cast<int>(coin) == -2147483648)
	{
		std::cout << "Error: too large a number." << std::endl;
		return (1);
	}
	return (0);
}

void BitcoinExchange::executeInputFile(std::fstream &file)
{
	std::string line;

	while(std::getline(file, line))
	{
		if (line.empty())
			continue;
		else
		{
			std::string	date;
			_uint64		coin;
			size_t		pos;

			pos = line.find('|');
			date = line.substr(0, pos);
			line.erase(0, pos + 2);
			coin = std::atoll(line.c_str());

			if (checkInvalidPos(pos, line))
				continue;
			else if (checkInvalidDate(date))
				continue;
			else if (checkInvalidCoin(coin))
				continue;
			else
				std::cout << date << coin << std::endl;
			
		}
		
			
	}
}


BitcoinExchange::BitcoinExchange(std::string file)
{
	std::fstream data("data.csv");
	std::fstream inputFile(file.c_str());

	if (data.fail() || inputFile.fail())
		throw InvalidFile();
	createData(data);
	executeInputFile(inputFile);
}