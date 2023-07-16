#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm( void );
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &sc);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &sc);
		~RobotomyRequestForm( void );
};

#endif