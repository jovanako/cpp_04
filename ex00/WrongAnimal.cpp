#include "WrongAnimal.hpp"

#include <iostream>

WrongAnimal::WrongAnimal() : type("Wrong Animal") {
	std::cout << "WrongAnimal Default Constructor called for " << type << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type) {
	std::cout << "WrongAnimal Parametric Constructor called for " << type << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal & other) : type(other.type) {
	std::cout << "WrongAnimal Copy Constructor called for " << type << std::endl;
}

WrongAnimal & WrongAnimal::operator=(const WrongAnimal & other) {
	if (this != &other) {
		this->type = other.type;
		std::cout << "WrongAnimal Copy Assignment Operator called for " << type << std::endl;
	}
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal Destructor called for " << type << std::endl;
}

std::string WrongAnimal::getType() const {
	return type;
}

void WrongAnimal::makeSound() const {
	std::cout << "* Generic Wrong Animal sound *" << std::endl;
}