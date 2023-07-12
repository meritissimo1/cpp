#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Bureaucrat
{
	public:
		Bureaucrat( void );
		Bureaucrat(const Bureaucrat &b);
		Bureaucrat &operator=(const Bureaucrat &b);
		~Bureaucrat( void );
	
		void setName(std::string const name);
		std::string getName(void) const;

		void	setGrade(const int grade);
		int		getGrade(void) const; 

		void incrementGrade(void);
		void decrementGrade(void);

		//GradeTooHighException;
		//GradeTooLowException;

	private:
		std::string const _name;
		int _grade;
};

std::ostream	operator<<(std::ostream &o, const Bureaucrat &b);

#endif
