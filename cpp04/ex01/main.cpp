#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(void)
{
	Animal	*animal = new Animal();
	Animal	*dog = new Dog();
	Animal	*cat = new Cat();
	Animal	dog1;
	WrongAnimal *wronganimal = new WrongAnimal();
	WrongAnimal *wrongcat = new WrongCat();
	Animal *lucas[10];

	dog1 = *dog;

	for (int i = 0; i < 2; i++)
	{
		if (i < 5)
			lucas[i] = new Dog();
		else
			lucas[i] = new Cat();
	}

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

	for (int i = 0; i < 2; i++)
		delete lucas[i];
	return (0);
}
