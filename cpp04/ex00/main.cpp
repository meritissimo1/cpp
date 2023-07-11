#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(void)
{
	Animal	*animal = new Animal();
	Animal	*dog = new Dog();
	Animal	*cat = new Cat();
	WrongAnimal *wronganimal = new WrongAnimal();
	WrongAnimal *wrongcat = new WrongCat();	

	std::cout << std::endl;
	animal->makeSound();
	cat->makeSound();
	dog->makeSound();
	wrongcat->makeSound();
	wronganimal->makeSound();

	std::cout << std::endl;
	std::cout << animal->getType() << std::endl
	<< dog->getType() << std::endl
	<< cat->getType() << std::endl
	<< wronganimal->getType() << std::endl
	<< wrongcat->getType() << std::endl;
	std::cout << std::endl;

	delete animal;
	delete dog;
	delete cat;
	delete wrongcat;
	delete wronganimal;
	return (0);
}
