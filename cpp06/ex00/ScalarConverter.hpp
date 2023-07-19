#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <cctype>
# include <limits>
# include <cmath>
# include <sstream>

# define INVALID "invalid"

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
