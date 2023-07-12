#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(void)
{
	AAnimal	*lade = new Dog();
	//AAnimal	lucas;	
	
	delete lade;
	return (0);
}
