#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <vector>
#include <string>
#include <iostream>

#include "../character/animal.h"
#include "../item/item.h"

namespace the_lion_king_saga {

	class Environment {
		protected:

		public:

			virtual std::vector<std::string> derections() const = 0;
			virtual Environment& neighbor(std::string) = 0;
			virtual std::string description() const = 0;
			virtual void enter(Animal&) = 0;
			virtual void leave(Animal&) = 0;

			void remove(Item&);
			void add(Item&);
	};
}
#endif
