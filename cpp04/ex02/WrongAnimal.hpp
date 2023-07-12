#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP 

# include <iostream>
# include <string>

class WrongAnimal
{
	public:
		WrongAnimal( void );
		WrongAnimal(const WrongAnimal &wa);
		WrongAnimal &operator=(const WrongAnimal &wa);
		~WrongAnimal( void );
		
		void makeSound(void) const;
		std::string getType(void) const;
		void setType(std::string type);

	protected:
		std::string _type;
};

std::ostream	&operator<<(std::ostream &o, const WrongAnimal &wa);

#endif