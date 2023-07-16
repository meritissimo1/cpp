#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm( void );
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &sc);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &sc);
		~PresidentialPardonForm( void );

		void execute(Bureaucrat const &executor) const;
};

#endif