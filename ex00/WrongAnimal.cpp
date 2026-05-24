#include "WrongAnimal.hpp"
#include "Colors.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : type("Wrong Animal") {
	std::cout << MAGENTA << "WrongAnimal Default Constructor called for " << type << RESET << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type) {
	std::cout << MAGENTA << "WrongAnimal Parametric Constructor called for " << type << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal & other) : type(other.type) {
	std::cout << MAGENTA << "WrongAnimal Copy Constructor called for " << type << RESET << std::endl;
}

WrongAnimal & WrongAnimal::operator=(const WrongAnimal & other) {
	if (this != &other) {
		this->type = other.type;
		std::cout << MAGENTA << "WrongAnimal Copy Assignment Operator called for " << type << RESET << std::endl;
	}
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << MAGENTA << "WrongAnimal Destructor called for " << type << RESET << std::endl;
}

std::string WrongAnimal::getType() const {
	return type;
}

void WrongAnimal::makeSound() const {
	std::cout << "* Generic Wrong Animal sound *" << std::endl;
}