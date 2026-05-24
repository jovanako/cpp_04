#include "Brain.hpp"
#include "Colors.hpp"
#include <iostream>

Brain::Brain() {
	std::cout << YELLOW << "Brain Default Constructor called" << RESET << std::endl;
	// ideas array will be initialized with 100 empty strings
}

Brain::Brain(const Brain& other) {
	std::cout << YELLOW << "Brain Copy Constructor called" << RESET << std::endl;
	*this = other;
}

Brain & Brain::operator=(const Brain& other) {
	std::cout << YELLOW << "Brain Copy Assignment Operator called" << RESET << std::endl;
	if (this != &other) {
		for (int i = 0; i < 100; i++)
			this->ideas[i] = other.ideas[i];
	}
	return *this;
}

Brain::~Brain() {
	std::cout << YELLOW << "Brain Destructor called" << RESET << std::endl;
}

std::string Brain::getIdea(int index) const {
	if (index >= 0 && index < 100)
		return this->ideas[index];
	return "";
}

void Brain::setIdea(int index, const std::string& idea) {
	if (index >= 0 && index < 100)
		this->ideas[index] = idea;
}