#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

# define SHRUBBERY \
"\
     .     .  .           +     .      .          .\n\
     .       .      .     #       .           .\n\
        .      .         ###            .      .      .\n\
      .      .   #:. .:##*##:. .:#  .      .\n\
          .      . *####*###*####*  .\n\
       .     #:.    .:#*###*#:.    .:#  .        .       .\n\
  .             *#########*#########*        .        .\n\
        .    #:.  *####*###*####*  .:#   .       .\n\
     .     .  #######**##*##**#######                  .\n\
                .##*#####*#####*##           .      .\n\
    .   #:. ...  .:##*###*###*##:.  ... .:#     .\n\
      .     *#######*##*#####*##*#######*      .     .\n\
    .    .     #####**#######**#####    .      .\n\
            .     *      000      *    .     .\n\
       .         .   .   000     .        .       .\n\
.. .. ..................O000O........................ ...... ...\n\
"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm( void );
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &sc);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &sc);
		~ShrubberyCreationForm( void );

		void execute(Bureaucrat const &executor) const;
};

#endif