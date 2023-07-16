#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern( void );
		Intern(const Intern &sc);
		Intern &operator=(const Intern &sc);
		~Intern( void );

		AForm* makeForm(std::string form, std::string target);

		class InvalidFormException : public std::exception
		{
			virtual const char* what() const throw();
		};
};

#endif