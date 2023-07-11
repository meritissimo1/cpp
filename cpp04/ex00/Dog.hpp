#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class	Dog : public Animal
{
	public:
		Dog( void );
		Dog(const Dog &d);
		Dog &operator=(const Dog &d);
		~Dog( void );
		void makeSound(void) const;

};

std::ostream	&operator<<(std::ostream &o, const Dog &a);

#endif