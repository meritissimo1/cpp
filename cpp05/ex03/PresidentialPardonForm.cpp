#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) : AForm("PresidentialPardonForm", 25, 5, "target")
{
	std::cout << "PresidentialPardonForm default constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5, target)
{
	std::cout << "PresidentialPardonForm constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &pp) : AForm("PresidentialPardonForm", 25, 5, pp.getTarget())
{
	std::cout << "PresidentialPardonForm Copy constructor called\n";
	*this = pp;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &pp)
{
	std::cout << "PresidentialPardonForm Assignment operator called\n";
	if (this != &pp)
	{
		this->setName(pp.getName());
		this->setGradeSign(pp.getGradeSign());
		this->setGradeSign(pp.getGradeSign());
		this->setGradeExecute(pp.getGradeExecute());
		this->setIsSigned(pp.getIsSigned());
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
	std::cout << "PresidentialPardonForm destructor called\n";
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);
	std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox\n";
}