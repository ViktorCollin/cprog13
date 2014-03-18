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
			Environment();

			virtual std::vector<std::string> derections() const;
			virtual Environment neighbor(std::string);
			virtual std::string description() const;
			virtual void enter(Animal);
			virtual void leave(Animal);

			void remove(Item);
			void add(Item);
	};
}
#endif
