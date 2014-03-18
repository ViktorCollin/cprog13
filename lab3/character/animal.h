#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

namespace the_lion_king_saga {

	class Animal {
		protected:

		public:
			Animal();
			virtual std::string type();
			virtual std::string name();

	};
}

#endif
