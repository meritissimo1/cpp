#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
	public:
		Bureaucrat( void );
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(const Bureaucrat &b);
		Bureaucrat &operator=(Bureaucrat const &b);
		~Bureaucrat( void );

		void setName(std::string const name);
		std::string getName(void) const;

		void	setGrade(const int grade);
		int		getGrade(void) const;

		void	signForm(AForm &f);
		void executeForm(AForm const & form);

		void incrementGrade(void);
		void decrementGrade(void);

		class	GradeTooLowException : public std::exception
		{	
			const char *what() const throw()
			{
				return ("This grade is too low\n");
			}
		};

		class	GradeTooHighException : public std::exception
		{
			const char *what() const throw()
			{
				return ("This grade is too high\n");
			}
		};

	private:
		const std::string _name;
		int _grade;
};

std::ostream	&operator<<(std::ostream &o, const Bureaucrat &b);

#endif
