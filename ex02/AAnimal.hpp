#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>

class AAnimal {
	protected:
		std::string type;
	public:
		AAnimal();		
		AAnimal(std::string type);
		AAnimal(const AAnimal & other);
		AAnimal & operator=(const AAnimal & other);
		virtual ~AAnimal();

		std::string getType() const;

		virtual void makeSound() const = 0;	// a pure virtual function
};

#endif