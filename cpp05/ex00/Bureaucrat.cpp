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


Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
	if (grade > 150)
		std::cout << "lowexception\n";
	else if (grade < 1)
		std::cout << "highexception\n";
	this->_grade = grade;
	std::cout << "Bureaucrat Constructor called\n";
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &b)
{
    if (this != &b)
    {
        std::cout << "Buraucrat Copy assignment operator called\n";
        this->_name = b._name;
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
    this->_name = name;
}

std::string Bureaucrat::getName(void) const
{
    return (this->_name);
}

void	Bureaucrat::setGrade(const int grade)
{
	if (grade > 150)
		std::cout << "lowexception\n";
	else if (grade < 1)
		std::cout << "high exception\n";

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
		std::cout << "lowexception";
    this->_grade++;
}

std::ostream	&operator<<(std::ostream &o, const Bureaucrat &b)
{
    o << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
    return (o);
}
