#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

namespace the_lion_king_saga {

	class Animal {
		protected:
			std::string _name;
			int _health;

		public:
			Animal(std::string, int);
			std::string name();
			int health();
			virtual int attack(Animal*) = 0;

	};
}

#endif
