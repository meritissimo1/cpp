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

BitcoinExchange::BitcoinExchange(std::string file)
{
	std::fstream data("data.csv");
	std::fstream inputFile(file.c_str());

	if (data.fail() || inputFile.fail())
		throw InvalidFile();
	createData(data);
	//executeInputFile(inputFile);
}