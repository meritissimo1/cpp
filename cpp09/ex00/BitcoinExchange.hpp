#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <algorithm>
# include <string>
# include <fstream>
# include <map>

typedef long long int _uint64;

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
		std::map<std::string, float> _dataCSV;


};

#endif
