#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

# define SHRUBBERY "arvri"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm( void );
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &sc);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &sc);
		~ShrubberyCreationForm( void );
};

#endif