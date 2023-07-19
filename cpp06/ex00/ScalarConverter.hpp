#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <cmath>
# include <sstream>

class ScalarConverter
{
	public:
		ScalarConverter( void );
		ScalarConverter(const ScalarConverter &sc);
		ScalarConverter &operator=(const ScalarConverter &sc);
		~ScalarConverter( void );

		static void convert(const std::string strToconvert);
};

#endif
