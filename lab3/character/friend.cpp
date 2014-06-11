#include "friend.h"

namespace the_lion_king_saga {

	Friend::Friend(std::string name, int health, std::string speach): Animal::Animal(name, health, speach){
	}

	void Friend::attack(Animal* a) {
		srand (time(NULL));
		int damage = rand() % 100 + 1;
		std::cout << _name << " attacks " << a->name() << std::endl;
		std::cout << "Did " << damage << " damage and " << a->name() << "'s health is now " << a->health(damage)       << std::endl;
	}
}
