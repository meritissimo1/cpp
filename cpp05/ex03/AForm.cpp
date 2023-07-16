#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm( void ) : _gradeSign(1), _gradeExecute(1)
{
	const_cast<std::string&>(this->_name) = "AForm";
	this->_isSigned = false;
	std::cout << "AForm Default constructor called\n";
}

AForm::AForm(const AForm &b) : _gradeSign(1), _gradeExecute(1)
{
	const_cast<std::string&>(this->_name) = "AForm";
	std::cout << "AForm copy constructor called\n";
	*this = b;
}

AForm::AForm(const std::string name, const int gradeSign, const int gradeExecute, const std::string target) : _name(name), _gradeSign(gradeSign), _gradeExecute(gradeExecute), _target(target)
{
	if (gradeSign > 150 || gradeExecute > 150)
		throw AForm::GradeTooLowException();
	else if (gradeSign < 1 || gradeExecute < 1)
		throw AForm::GradeTooHighException();
	this->_isSigned = false;
	std::cout << "AForm Constructor called\n";
}

AForm &AForm::operator=(AForm const &b)
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

void	AForm::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > this->_gradeSign)
		throw GradeTooLowException();
	else if (this->_isSigned)
		throw AlreadySigned();
	this->_isSigned = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getGradeExecute())
		throw AForm::GradeTooLowException();
	else if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
}

AForm::~AForm( void )
{
	std::cout << "AForm destructor called\n";
}

void AForm::setName(std::string const name)
{
	const_cast<std::string&>(this->_name) = name;
}

std::string AForm::getName(void) const
{
	return (this->_name);
}

void	AForm::setGradeSign(const int grade)
{
	const_cast<int&>(this->_gradeSign) = grade;
}

int		AForm::getGradeSign(void) const
{
	return (this->_gradeSign);
}

void	AForm::setGradeExecute(const int grade)
{
	const_cast<int&>(this->_gradeExecute) = grade;
}

int		AForm::getGradeExecute(void) const
{
	return (this->_gradeExecute);
}

void	AForm::setIsSigned(const bool sign)
{
	this->_isSigned = sign;
}

bool	AForm::getIsSigned(void) const
{
	return (this->_isSigned);
}

void	AForm::setTarget(const std::string target)
{
	const_cast<std::string&>(this->_target) = target;
}

std::string AForm::getTarget(void) const
{
	return (this->_target);
}

const char*	AForm::GradeTooHighException::what(void) const throw()
{
	return "This grade is too high\n";
}

const char*	AForm::GradeTooLowException::what(void) const throw()
{
	return "This grade is too Low\n";
}

const char*	AForm::AlreadySigned::what(void) const throw()
{
	return "the form is Already Signed\n";
}

const char*	AForm::FormNotSignedException::what(void) const throw()
{
	return "Form not Signed\n";
}

std::ostream	&operator<<(std::ostream &o, const AForm &b)
{
	o << "AForm name: " << b.getName() << std::endl;
	o << "AForm grade: " << b.getGradeSign() << std::endl;
	o << "AForm execute: " << b.getGradeExecute() << std::endl;
	o << "AForm is signed: " << b.getIsSigned() << std::endl;
	return (o);
}
