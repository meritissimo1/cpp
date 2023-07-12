#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class	Cat : public Animal
{
	public:
		Cat( void );
		Cat(const Cat &c);
		Cat &operator=(const Cat &c);
		~Cat( void );

		void makeSound(void) const;
	
	private:
		Brain *_brain;

};

std::ostream	&operator<<(std::ostream &o, const Cat &a);

#endif