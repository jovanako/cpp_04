#include "Cat.hpp"
#include "Colors.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat") {
	std::cout << GREEN << "Cat Default Constructor called" << RESET << std::endl;
}

Cat::Cat(const Cat & other) : Animal(other) {
	std::cout << GREEN << "Cat Copy Constructor called" << RESET << std::endl;
}

Cat & Cat::operator=(const Cat & other) {
	std::cout << GREEN << "Cat Copy Assignment Operator called" << RESET << std::endl;
	if (this != &other)
		Animal::operator=(other);
	return *this;
}

Cat::~Cat() {
	std::cout << GREEN << "Cat Destructor called" << RESET << std::endl;
}

void Cat::makeSound() const {
	std::cout << "* Meow! Meow! *" << std::endl;
}
