#include "cat.h"

namespace the_lion_king_saga {

	Cat::Cat(std::string name, int health): Animal::Animal(name, health){
	}

	int Cat::attack(Animal* a) {
		std::cout << "No attack implemented for " << name() << std::endl;
	}
}
