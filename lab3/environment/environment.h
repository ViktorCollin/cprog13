#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <map>
#include <string>
#include <iostream>
#include <exception>
#include <memory>

#include "../character/animal.h"
#include "../item/item.h"
#include "../enums.cpp"

namespace the_lion_king_saga {

	class Environment {

		protected:
			std::map<std::string,std::unique_ptr<Item>> _items;
			std::map<std::string,std::unique_ptr<Animal>> _animals;
			std::string _shortDescription;
			std::string _description;
		public:
			std::map<Direction, std::shared_ptr<Environment>> _neighbors;

			Environment(std::string);
			virtual std::map<std::string, std::string> directions() const = 0;
			std::shared_ptr<Environment> getNeighbor(Direction);
			void addNeighbor(std::shared_ptr<Environment>, Direction);
			std::string description() const;
			std::string shortDescription() const;

			void addAnimal(std::unique_ptr<Animal>);
			Animal* getAnimal(std::string);

			std::unique_ptr<Item> get(std::string s);
			void add(std::unique_ptr<Item>);
	};
}
#endif
