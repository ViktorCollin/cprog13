#ifndef FRIEND_H
#define FRIEND_H

#include <string>
#include "animal.h"
#include <iostream>

namespace the_lion_king_saga {

	class Friend : public Animal {
		protected:

		public:
			Friend(std::string, int, std::string);
			virtual void attack(Animal*);
	};
}


#endif
