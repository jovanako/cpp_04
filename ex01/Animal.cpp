#include "Animal.hpp"
#include "Colors.hpp"
#include <iostream>

Animal::Animal() : type("Animal") {
	std::cout << CYAN << "Animal Default Constructor called for " << type << RESET << std::endl;
}

Animal::Animal(std::string type) : type(type) {
	std::cout << CYAN << "Animal Parametric Constructor called for " << type << RESET << std::endl;
}

Animal::Animal(const Animal & other) : type(other.type) {
	std::cout << CYAN << "Animal Copy Constructor called for " << type << RESET << std::endl;
}

Animal & Animal::operator=(const Animal & other) {
	if (this != &other) {
		this->type = other.type;
		std::cout << CYAN << "Animal Copy Assignment Operator called for " << type << RESET << std::endl;
	}
	return *this;
}

Animal::~Animal() {
	std::cout << CYAN << "Animal Destructor called for " << type << RESET << std::endl;
}

std::string Animal::getType() const {
	return type;
}

void Animal::makeSound() const {
	std::cout << "* Generic animal noise *" << std::endl;
}