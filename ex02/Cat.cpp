#include "Cat.hpp"
#include "Colors.hpp"
#include <iostream>

Cat::Cat() : AAnimal("Cat") {
	brain = new Brain();
	std::cout << GREEN << "Cat Default Constructor called" << RESET << std::endl;
}

Cat::Cat(const Cat & other) : AAnimal(other) {
	std::cout << GREEN << "Cat Copy Constructor called" << RESET << std::endl;
	this->brain = new Brain(*other.brain);
}

Cat & Cat::operator=(const Cat & other) {
	std::cout << GREEN << "Cat Copy Assignment Operator called" << RESET << std::endl;
	if (this != &other) {
		AAnimal::operator=(other);
		delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	return *this;
}

Cat::~Cat() {
	std::cout << GREEN << "Cat Destructor called" << RESET << std::endl;
	delete brain;
}

void Cat::makeSound() const {
	std::cout << "* Meow! Meow! *" << std::endl;
}

Brain& Cat::getBrain() {
	return *brain;
}
