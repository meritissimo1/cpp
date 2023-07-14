#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void )
{
	const_cast<std::string&>(this->_name) = "Bureaucrat";
	this->_grade = 1;
	std::cout << "Bureaucrat Default constructor called\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat &b)
{
	std::cout << "Bureaucrat copy constructor called\n";
	*this = b;
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name), _grade(grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	std::cout << "Bureaucrat Constructor called\n";
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &b)
{
	if (this != &b)
	{
		std::cout << "Buraucrat Copy assignment operator called\n";
		const_cast<std::string&>(this->_name) = b._name;
		this->_grade = b._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat( void )
{
	std::cout << "Bureaucrat destructor called\n";
}

void	Bureaucrat::setName(std::string const name)
{
	const_cast<std::string&>(this->_name) = name;
}

std::string Bureaucrat::getName(void) const
{
	return (this->_name);
}

void	Bureaucrat::setGrade(const int grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade = grade;
}

int		Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::incrementGrade(void)
{
	if (this->_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
}

void	Bureaucrat::decrementGrade(void)
{
	if (this->_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

void	Bureaucrat::signForm(Form &f)
{
	try
	{
		f.beSigned(*this);
		std::cout << getName() << " signed " << f.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << getName() << " couldn’t sign " << f.getName() << 
		" because " << e.what() << std::endl;
	}
}

std::ostream	&operator<<(std::ostream &o, const Bureaucrat &b)
{
	o << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
	return (o);
}
