#include "cat.h"

namespace the_lion_king_saga {

	Cat::Cat(std::string name, int health): Animal::Animal(name, health){
	}

	void Cat::attack(Animal* a) {
		srand (time(NULL));
		int damage = rand() % 100 + 1;
		std::cout << _name << " attacks " << a->name() << std::endl;
		std::cout << "Did " << damage << " damage and " << a->name() << "'s health is now " << a->health(damage)       << std::endl;
	}
}
