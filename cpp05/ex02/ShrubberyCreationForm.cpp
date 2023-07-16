#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ) : AForm("ShrubberyCreationForm", 145, 137, "target")
{
	std::cout << "ShrubberyCreationForm default constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137, target)
{
	std::cout << "ShrubberyCreationForm constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &pp) : AForm("ShrubberyCreationForm", 145, 137, pp.getTarget())
{
	std::cout << "ShrubberyCreationForm Copy constructor called\n";
	*this = pp;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &pp)
{
	std::cout << "ShrubberyCreationForm Assignment operator called\n";
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

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
	std::cout << "ShrubberyCreationForm destructor called\n";
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::string	outputFile;

	AForm::execute(executor);
	outputFile = this->getTarget() + "_shrubbery";
	std::ofstream outfile(outputFile.c_str());
	if (outfile.fail())
		std::cout << "Fail to open " << this->getTarget() + "_shrubbery" << std::endl;
	else
		outfile << SHRUBBERY;	
}