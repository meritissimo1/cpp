#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>

class Bureaucrat;

class AForm
{
	public:
		AForm( void );
		AForm(const AForm &b);
		AForm(const std::string name, const int gradeSign, const int gradeExecute, const std::string target);
		AForm &operator=(AForm const &b);
		~AForm( void );

		void setName(std::string const name);
		std::string getName(void) const;
		void	setGradeSign(const int grade);
		int		getGradeSign(void) const;	
		void	setGradeExecute(const int grade);
		int		getGradeExecute(void) const;
		void	setIsSigned(const bool sign);
		bool	getIsSigned(void) const;
		void	setTarget(const std::string target);
		std::string getTarget(void) const;

		 virtual void	beSigned(Bureaucrat &b);
		 virtual void execute(Bureaucrat const & executor) const  = 0;

		class	GradeTooLowException : public std::exception
		{
			const char *what() const throw();
		};

		class	GradeTooHighException : public std::exception
		{
			const char *what() const throw();
		};

		class	AlreadySigned : public std::exception
		{
			const char *what() const throw();
		};
		
		class FormNotSignedException : public std::exception
		{
			const char *what() const throw();
		};

	private:
		const std::string _name;
		bool	_isSigned;
		const int _gradeSign;
		const int _gradeExecute;
		std::string const	_target;
};

std::ostream	&operator<<(std::ostream &o, const AForm &b);

#endif