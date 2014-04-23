#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <map>
#include <string>
#include <iostream>

#include "../character/animal.h"
#include "../item/item.h"

namespace the_lion_king_saga {

	class Environment {

		protected:
			std::map<std::string, Environment&> neigbors;
			std::map<std::string,Item*> _items;
			std::string _shortDescription;
			std::string _description;
		public:
			Environment();
			virtual std::map<std::string, std::string> directions() const = 0;
			virtual Environment& neighbor(std::string) = 0;
			std::string description() const;
			std::string shortDescription() const;
			virtual void enter(Animal&) = 0;
			virtual void leave(Animal&) = 0;

			Item& get(std::string s);
			void add(Item&);
	};
}
#endif
