#include "Dog.hpp"
#include "Colors.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog") {
	std::cout << GREEN << "Dog Default Constructor called" << RESET << std::endl;
}

Dog::Dog(const Dog & other) : Animal(other) {
	std::cout << GREEN << "Dog Copy Constructor called" << RESET << std::endl;
}

Dog & Dog::operator=(const Dog & other) {
	std::cout << GREEN << "Dog Copy Assignment Operator called" << RESET << std::endl;
	if (this != &other)
		Animal::operator=(other);
	return *this;
}

Dog::~Dog() {
	std::cout << GREEN << "Dog Destructor called" << RESET << std::endl;
}

void Dog::makeSound() const {
	std::cout << "* Woof! Woof! *" << std::endl;
}