#include "animal.h"

namespace the_lion_king_saga {

	Animal::Animal(std::string name, int health): _name(name), _health(health) { }

	std::string Animal::name() {
		return _name;
	}

	int Animal::health() {
		return _health;
	}
}
