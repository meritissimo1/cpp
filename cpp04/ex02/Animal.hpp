#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>
# include "Brain.hpp"

class	AAnimal
{
	public:
		AAnimal( void );
		AAnimal(const AAnimal &a);
		AAnimal &operator=(const AAnimal &a);
		virtual ~AAnimal ( void );
		
		virtual void makeSound(void) const = 0;
		std::string getType(void) const;
		void		setType(std::string type);

	protected:
		std::string _type;
};

std::ostream	&operator<<(std::ostream &o, const AAnimal &a);

#endif
