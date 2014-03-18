#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

namespace the_lion_king_saga {

	class Animal {
		protected:

		public:
			Animal();
			virtual std::string type() = 0;
			virtual std::string name() = 0;

	};
}

#endif
