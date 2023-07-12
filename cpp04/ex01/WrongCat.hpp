#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP 

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat( void );
		WrongCat(const WrongCat &wa);
		WrongCat &operator=(const WrongCat &wa);
		~WrongCat( void );
		
		void makeSound(void) const;

};

std::ostream	&operator<<(std::ostream &o, const WrongCat &wa);

#endif