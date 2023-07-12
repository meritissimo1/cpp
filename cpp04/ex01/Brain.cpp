#include "Animal.hpp"

Brain::Brain( void ) 
{
	std::cout << "Brain Default constructor called\n";
}

Brain::Brain(const Brain &a)
{
	std::cout << "Brain Copy constructor called\n";
	*this = a;
}

Brain	&Brain::operator=(const Brain &a)
{
	std::cout << "Brain Copy Assignment operator called\n";
	if (this != &a)
		for(int i = 0; i < 100; i++)
			this->ideas[i] = a.ideas[i];
	return (*this);
}

Brain::~Brain( void )
{
	std::cout << "Brain Destructor called\n";
}
