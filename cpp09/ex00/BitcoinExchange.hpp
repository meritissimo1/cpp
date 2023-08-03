#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <algorithm>
# include <string>
# include <fstream>
# include <map>

class BitcoinExchange
{
public:
		BitcoinExchange( void );
		BitcoinExchange(const BitcoinExchange &be);
		BitcoinExchange &operator=(const BitcoinExchange &be);
		BitcoinExchange(const std::string file);
		~BitcoinExchange( void );

		void createData(std::fstream &data);
		void executeInputFile(std::fstream &data);
		void execLine(std::string date, double coin);
		void closestValue(std::map<std::string, double>& dataCSV, const std::string& date);

	class InvalidFile : public std::exception
	{
		public:
		const char *what() const throw()
		{
			return ("Invalid file\n");
		}
	};

	private:
		const std::string _file;
		std::map<std::string, double> _dataCSV;
		std::map<std::string, double>::iterator _it;


};

#endif
