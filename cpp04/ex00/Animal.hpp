#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class	Animal
{
	public:
		Animal( void );
		Animal(const Animal &a);
		Animal &operator=(const Animal &a);
		virtual ~Animal ( void );
		
		virtual void makeSound(void) const;
		std::string getType(void) const;
		void		setType(std::string type);

	protected:
		std::string _type;
};

std::ostream	&operator<<(std::ostream &o, const Animal &a);

#endif