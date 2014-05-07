#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <map>
#include <string>
#include <iostream>
#include <exception>

#include "../character/animal.h"
#include "../item/item.h"
#include "../enums.cpp"

namespace the_lion_king_saga {

	class Environment {

		protected:
			std::map<std::string,Item*> _items;
			std::string _shortDescription;
		public:
			std::string _description;
			std::map<direction, Environment*> _neighbors;

			Environment();
			virtual std::map<std::string, std::string> directions() const = 0;
			Environment& getNeighbor(direction);
			void addNeighbor(Environment&, direction);
			std::string description() const;
			std::string shortDescription() const;
			virtual void enter(Animal&) = 0;
			virtual void leave(Animal&) = 0;

			Item& get(std::string s);
			void add(Item&);
	};
}
#endif
