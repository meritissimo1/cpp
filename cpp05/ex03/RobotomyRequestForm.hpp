#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <cstdlib>
# include <ctime>

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm( void );
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &sc);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &sc);
		~RobotomyRequestForm( void );

		void execute(Bureaucrat const &executor) const;
};

#endif