#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include "animal.h"
#include <iostream>

namespace the_lion_king_saga {

	class Enemy : public Animal {
		protected:

		public:
			Enemy(std::string, int, std::string);
			virtual void attack(Animal*);
	};
}


#endif
