#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Colors.hpp"
#include <iostream>

int main() {
	std::cout << BOLD_WHITE << "======== SUBJECT TESTS ========" << RESET << std::endl;

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " <<std::endl; // dog type
	std::cout << i->getType() << " " <<std::endl; // cat type

	i->makeSound(); // will output the cat sound
	j->makeSound(); // will output the dog sound
	meta->makeSound(); // will output the generic animal sound

	std::cout << std::endl;

	std::cout << "-------- Deleting Subject Animals --------" << std::endl;
	delete meta;
	delete j;
	delete i;

	std::cout << std::endl;

	std::cout << BOLD_WHITE << "======== WRONG ANIMAL TESTS ========" << RESET << std::endl;

	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << wrongCat->getType() << " " << std::endl; // wrong cat type

	wrongCat->makeSound(); // will output the WrongAnimal sound due to static binding
	wrongMeta->makeSound();

	std::cout << std::endl;

	std::cout << "-------- Deleting Wrong Animals --------" << std::endl;
	delete wrongMeta;
	delete wrongCat; //notice during execution that ~WrongCat is never called

	std::cout << std::endl;

	std::cout << BOLD_WHITE << "======== ADDITIONAL DEEP COPY TESTS ========" << RESET << std::endl;

	std::cout << std::endl;

	std::cout << "--- Creating a Dog and copying it ---" << std::endl;
	Dog originalDog;
	std::cout << "Original Dog Type: " << originalDog.getType() << std::endl;

	std::cout << std::endl;

	Dog copyDog(originalDog);
	std::cout << "Copy Dog Type: " << copyDog.getType() << std::endl;

	std::cout << std::endl;

	Dog assignedDog;
	assignedDog = originalDog;
	std::cout << "Assigned Dog Type: " << assignedDog.getType() << std::endl;

	std::cout << std::endl;

	std::cout << "--- Scope Ending: Stack Deletions ---" << std::endl;
	return 0;
}