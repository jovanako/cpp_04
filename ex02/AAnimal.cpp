#include "AAnimal.hpp"
#include "Colors.hpp"
#include <iostream>

AAnimal::AAnimal() : type("AAnimal") {
	std::cout << CYAN << "AAnimal Default Constructor called for " << type << RESET << std::endl;
}

AAnimal::AAnimal(std::string type) : type(type) {
	std::cout << CYAN << "AAnimal Parametric Constructor called for " << type << RESET << std::endl;
}

AAnimal::AAnimal(const AAnimal & other) : type(other.type) {
	std::cout << CYAN << "AAnimal Copy Constructor called for " << type << RESET << std::endl;
}

AAnimal & AAnimal::operator=(const AAnimal & other) {
	if (this != &other) {
		this->type = other.type;
		std::cout << CYAN << "AAnimal Copy Assignment Operator called for " << type << RESET << std::endl;
	}
	return *this;
}

AAnimal::~AAnimal() {
	std::cout << CYAN << "AAnimal Destructor called for " << type << RESET << std::endl;
}

std::string AAnimal::getType() const {
	return type;
}