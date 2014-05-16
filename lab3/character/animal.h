#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

namespace the_lion_king_saga {

	class Animal {
		protected:
			std::string _name;
			int _health;
			bool _dead;

		public:
			Animal(std::string, int);
			std::string name();
			int health( int = 0);
			virtual void attack(Animal*) = 0;
			bool isDead();
	};
}

#endif
