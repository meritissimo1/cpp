#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(void)
{
	Animal	*animal = new Animal();
	std::cout << std::endl;
	Animal	*dog = new Dog();
	std::cout << std::endl;
	Animal	*cat = new Cat();
	std::cout << std::endl;
	Animal	dog1;
	std::cout << std::endl;
	WrongAnimal *wronganimal = new WrongAnimal();
	std::cout << std::endl;
	WrongAnimal *wrongcat = new WrongCat();
	std::cout << std::endl;
	Animal *lucas[4];
	std::cout << std::endl;



	for (int i = 0; i < 4; i++)
	{
		if (i < 2)
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

	for (int i = 0; i < 4; i++)
		delete lucas[i];
	return (0);
}
