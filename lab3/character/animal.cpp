#include "animal.h"

namespace the_lion_king_saga {

	Animal::Animal(std::string name, int health, std::string speach): 
		_name(name), 
		_health(health),
		_speach(speach),
	    _dead(false){ }

	std::string Animal::name() {
		if(isDead()) 
			return "The body of " + _name;
		return _name;
	}
	
	std::string Animal::getSpeach() {
		if(isDead()) 
			return "Dead animals can't talk";
		return _speach;
	}
	
	void Animal::setSpeach(std::string speach) {
		_speach = speach;
	}

	int Animal::health( int hit /* = 0 */) {
		_health -= hit;
		if(_health <= 0)  {
			_dead = true;
			_health = 0;
		}
		return _health;
	}

	bool Animal::isDead() {
		return _dead;
	}
}
