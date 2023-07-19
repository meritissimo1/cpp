#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <cmath>
# include <limits>
# include <iomanip>

# define INVALID "invalid"

class ScalarConverter
{
	public:
		ScalarConverter( void );
		ScalarConverter(const ScalarConverter &sc);
		ScalarConverter &operator=(const ScalarConverter &sc);
		~ScalarConverter( void );

		static void convert(std::string strToconvert);
};

#endif
