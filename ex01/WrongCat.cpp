#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal("Wrong Cat") {
	std::cout << "WrongCat Default Constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat & other) : WrongAnimal(other) {
	std::cout << "WrongCat Copy Constructor called" << std::endl;
}

WrongCat & WrongCat::operator=(const WrongCat & other) {
	if (this != &other) {
		this->type = other.type;
		std::cout << "WrongCat Copy Assignment Operator called" << std::endl;
	}
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat Destructor called" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "* Meow! Meow! *" << std::endl;
}