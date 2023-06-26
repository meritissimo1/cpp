#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

class	Harl
{


	public:
		void complain(std::string level);
		Harl(void);
		~Harl(void);
		enum enumLevels
		{
			DEBUG,
			INFO,
			WARNING,
			ERROR,
			TOTAL
		};
		struct enumMap
		{
			std::string	level;
			enumLevels	value;
		};

	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);

};

#endif
