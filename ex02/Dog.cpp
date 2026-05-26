#include "Dog.hpp"
#include "Colors.hpp"
#include <iostream>

Dog::Dog() : AAnimal("Dog") {
	brain = new Brain();
	std::cout << GREEN << "Dog Default Constructor called" << RESET << std::endl;
}

Dog::Dog(const Dog & other) : AAnimal(other) {
	std::cout << GREEN << "Dog Copy Constructor called" << RESET << std::endl;
	this->brain = new Brain(*other.brain);
}

Dog & Dog::operator=(const Dog & other) {
	std::cout << GREEN << "Dog Copy Assignment Operator called" << RESET << std::endl;
	if (this != &other) {
		AAnimal::operator=(other);
		delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	return *this;
}

Dog::~Dog() {
	std::cout << GREEN << "Dog Destructor called" << RESET << std::endl;
	delete brain;
}

void Dog::makeSound() const {
	std::cout << "* Woof! Woof! *" << std::endl;
}