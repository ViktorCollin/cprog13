#include "animal.h"

namespace the_lion_king_saga {

	Animal::Animal(std::string name, int health, std::string speach): 
		_name(name), 
		_health(health),
		_speach(speach),
	    _dead(false){ }

	std::string Animal::name() const{
		if(isDead()) 
			return "The body of " + _name;
		return _name;
	}
	
	void Animal::printSpeach() const{
		if(isDead()) 
			std::cout << "Dead animals can't talk" << std::endl;
        else
		std::cout << _speach << std::endl;
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

	bool Animal::isDead() const{
		return _dead;
	}
}
