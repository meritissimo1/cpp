#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ) : AForm("RobotomyRequestForm", 72, 45, "target")
{
	std::cout << "RobotomyRequestForm default constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45, target)
{
	std::cout << "RobotomyRequestForm constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &pp) : AForm("RobotomyRequestForm", 72, 45, pp.getTarget())
{
	std::cout << "RobotomyRequestForm Copy constructor called\n";
	*this = pp;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &pp)
{
	std::cout << "RobotomyRequestForm Assignment operator called\n";
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

RobotomyRequestForm::~RobotomyRequestForm( void )
{
	std::cout << "RobotomyRequestForm destructor called\n";
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);
	std::cout << "Txi tu txi tu purupupuuu" << std::endl;
	std::srand(std::time(0));
	int randomValue = std::rand();
	bool random = (randomValue % 2 == 0);
	if (random)
		std::cout << this->getTarget() << " has been robotomized\n";
	else
		std::cout << "Fail to robotimize\n";
}