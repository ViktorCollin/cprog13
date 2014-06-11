#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <iostream>

namespace the_lion_king_saga {

	class Animal {
		protected:
			std::string _name;
            std::string _speach;
			int _health;
			bool _dead;

		public:
			Animal(std::string, int, std::string);
			std::string name();
            void printSpeach();
            void setSpeach(std::string);
			int health( int = 0);
			virtual void attack(Animal*) = 0;
			bool isDead();
	};
}

#endif
