#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void )
{
    std::cout << "Bureaucrat Default constructor called\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat &b)
{
    std::cout << "Bureaucrat copy constructor called\n";
    *this = b;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &b)
{
    if (this != &b)
    {
		std::cout << "Buraucrat Copy assignment operator called\n";
        this->_name = b.getName();
        this->_grade = b.getGrade();
    }
    return (*this);
}

Bureaucrat::~Bureaucrat( void )
{
	std::cout << "Bureaucrat destructor called\n";
}

void	Bureaucrat::setName(std::string const name)
{
	this->_name = name;
}

std::string Bureaucrat::getName(void) const
{
	return (this->_name);
}

void	Bureaucrat::setGrade(const int grade)
{
	this->_grade = grade;
}

int		Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::incrementGrade(void)
{
	this->_grade--;
}

void	Bureaucrat::decrementGrade(void)
{
	this->_grade++;
}

std::ostream	operator<<(std::ostream &o, const Bureaucrat &b)
{
	o << this->_name << ", bureaucrat grade " << this->_grade << std::endl;
	return (o);
}
