#include "Form.hpp"

Form::Form( void ) : _gradeSign(1), _gradeExecute(1)
{
	const_cast<std::string&>(this->_name) = "Form";
	this->_isSigned = false;
	std::cout << "Form Default constructor called\n";
}

Form::Form(const Form &b) : _gradeSign(b._gradeSign), _gradeExecute(b._gradeExecute)
{
	const_cast<std::string&>(this->_name) = b._name;
	std::cout << "Form copy constructor called\n";
	*this = b;
}

Form::Form(const std::string name, const int gradeSign, const int gradeExecute) : _name(name), _gradeSign(gradeSign), _gradeExecute(gradeExecute)
{
	if (gradeSign > 150 || gradeExecute > 150)
		throw Form::GradeTooLowException();
	else if (gradeSign < 1 || gradeExecute < 1)
		throw Form::GradeTooHighException();
	this->_isSigned = false;
	std::cout << "Form Constructor called\n";
}

Form &Form::operator=(Form const &b)
{
	if (this != &b)
	{
		std::cout << "Buraucrat Copy assignment operator called\n";
		const_cast<std::string&>(this->_name) = b._name;
		const_cast <int &>(this->_gradeSign) = b._gradeSign;
		const_cast <int &>(this->_gradeExecute) = b._gradeExecute;
		this->_isSigned = b._isSigned;
	}
	return (*this);
}

void	Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() >  this->_gradeSign)
		throw GradeTooLowException();
	else if (this->_isSigned)
		throw AlreadySigned();
	this->_isSigned = true;
}

Form::~Form( void )
{
	std::cout << "Form destructor called\n";
}

std::string Form::getName(void) const
{
	return (this->_name);
}

int		Form::getGradeSign(void) const
{
	return (this->_gradeSign);
}

int		Form::getGradeExecute(void) const
{
	return (this->_gradeExecute);
}

bool	Form::getIsSigned(void) const
{
	return (this->_isSigned);
}

std::ostream	&operator<<(std::ostream &o, const Form &b)
{
	o << "Form name: " << b.getName() << std::endl;
	o << "Form grade: " << b.getGradeSign() << std::endl;
	o << "Form execute: " << b.getGradeExecute() << std::endl;
	o << "Form is signed: " << b.getIsSigned() << std::endl;
	return (o);
}
