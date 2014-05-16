#ifndef CAT_H
#define CAT_H

#include <string>
#include "animal.h"
#include <iostream>

namespace the_lion_king_saga {

	class Cat : public Animal {
		protected:

		public:
			Cat(std::string, int);
			virtual void attack(Animal*);
	};
}


#endif
