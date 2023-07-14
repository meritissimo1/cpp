#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form( void );
		Form(const Form &b);
		Form(const std::string name, const int gradeSign, const int gradeExecute);
		Form &operator=(Form const &b);
		~Form( void );

		void setName(std::string const name);
		std::string getName(void) const;

		void	setGradeSign(const int grade);
		int		getGradeSign(void) const;
		int		getGradeExecute(void) const;
		bool	getIsSigned(void) const;

		void	beSigned(Bureaucrat &b);

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

		class	AlreadySigned : public std::exception
		{
			const char *what() const throw()
			{
				return ("the form is Already Signed\n");
			}
		};

	private:
		const std::string _name;
		bool	_isSigned;
		const int _gradeSign;
		const int _gradeExecute;
};

std::ostream	&operator<<(std::ostream &o, const Form &b);

#endif