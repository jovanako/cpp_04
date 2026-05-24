#include "Animal.hpp"

#include <iostream>

Animal::Animal() : type("Animal") {
	std::cout << "Animal Default Constructor called for " << type << std::endl;
}

Animal::Animal(std::string type) : type(type) {
	std::cout << "Animal Parametric Constructor called for " << type << std::endl;
}

Animal::Animal(const Animal & other) : type(other.type) {
	std::cout << "Animal Copy Constructor called for " << type << std::endl;
}

Animal & Animal::operator=(const Animal & other) {
	if (this != &other) {
		this->type = other.type;
		std::cout << "Animal Copy Assignment Operator called for " << type << std::endl;
	}
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal Destructor called for " << type << std::endl;
}

std::string Animal::getType() const {
	return type;
}

void Animal::makeSound() const {
	std::cout << "* Generic animal noise *" << std::endl;
}