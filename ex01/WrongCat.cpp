#include "WrongCat.hpp"
#include "Colors.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal("Wrong Cat") {
	std::cout << RED << "WrongCat Default Constructor called" << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat & other) : WrongAnimal(other) {
	std::cout << RED << "WrongCat Copy Constructor called" << RESET << std::endl;
}

WrongCat & WrongCat::operator=(const WrongCat & other) {
	if (this != &other) {
		this->type = other.type;
		std::cout << RED << "WrongCat Copy Assignment Operator called" << RESET << std::endl;
	}
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << RED << "WrongCat Destructor called" << RESET << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "* Meow! Meow! *" << std::endl;
}