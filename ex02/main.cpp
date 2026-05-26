#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include "Colors.hpp"
#include <iostream>

int main() {
	// const AAnimal* testAbstract = new AAnimal();
	// AAnimal concreteAbstract;

	std::cout << BOLD_WHITE << "\n============= ARRAY TESTS ==============" << RESET << std::endl;

	const int arraySize = 4;
	AAnimal* animals[arraySize];		// stack array holding pointers

	std::cout << BOLD_WHITE << "\n-------- Creating Animals Array --------" << RESET << std::endl;
	for (int i = 0; i < arraySize; i++) {
		if (i < arraySize / 2)
			animals[i] = new Dog();	// objects allocated individually on the heap
		else
			animals[i] = new Cat();	// objects allocated individually on the heap
		std::cout << "Created animals[" << i << "] with type: " << animals[i]->getType() << std::endl;
		std::cout << "---------------------------------------------" << std::endl;
	}

	std::cout << BOLD_WHITE << "\n-------- Deleting Animals Array --------" << RESET << std::endl;
	for (int i = 0; i < arraySize; i++) {
		std::cout << "Deleting animals[" << i << "]: " << std::endl;
		delete animals[i];
		std::cout << "---------------------------------------------" << std::endl;
	}
	std::cout << std::endl;

	std::cout << BOLD_WHITE << "\n=========== DEEP COPY TESTS ============" << RESET << std::endl;

	std::cout << BOLD_WHITE << "\n--- Create Basic Cat and Set an Idea ---" << RESET << std::endl;
	Cat* originalCat = new Cat();
	originalCat->getBrain().setIdea(0, "Push cup off the table");
	std::cout << "originalCat's idea: " << originalCat->getBrain().getIdea(0) << std::endl;	
	std::cout << "---------------------------------------------" << std::endl;

	std::cout << BOLD_WHITE << "\n--- Create a Copy via Copy Constructor ---" << RESET << std::endl;
	Cat* copyCat = new Cat(*originalCat);
	std::cout << "copyCat's idea: " << copyCat->getBrain().getIdea(0) << std::endl;	
	std::cout << "---------------------------------------------" << std::endl;

	std::cout << BOLD_WHITE << "\n--- Test Assignment Operator Deep Copy ---" << RESET << std::endl;
	Cat assignedCat;
	assignedCat = *originalCat;
	std::cout << "assignedCat's idea: " << assignedCat.getBrain().getIdea(0) << std::endl;	
	std::cout << "---------------------------------------------" << std::endl;

	std::cout << BOLD_WHITE << "\n--- Proving Independent Mindspace ---" << RESET << std::endl;
	copyCat->getBrain().setIdea(0, "Sleep for 16 hours instead");
	std::cout << "originalCat's idea 0: " << originalCat->getBrain().getIdea(0) << std::endl;
	std::cout << "copyCat's idea 0: " << copyCat->getBrain().getIdea(0) << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	
	std::cout << BOLD_WHITE << "\n--- Deleting Heap Copy Objects ---" << RESET << std::endl;
	delete originalCat;
	delete copyCat;
	std::cout << "---------------------------------------------" << std::endl;

	return 0;
}