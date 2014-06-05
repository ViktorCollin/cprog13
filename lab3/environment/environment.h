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
			std::map<Direction, Environment*> _neighbors;
			std::string _description;
			std::string _farAwayDescription;
			std::string _name;

		public:
			Environment(std::string, std::string, std::string);
			std::string name();
			virtual std::map<std::string, std::string> directions() const = 0;
			Environment* getNeighbor(Direction);
			void addNeighbor(Environment*, Direction);
			std::string description() const;
			std::string farAwayDescription() const;
			void printDescription() const;

			void addAnimal(std::unique_ptr<Animal>);
			Animal* getAnimal(std::string);

			std::unique_ptr<Item> get(std::string s);
			void add(std::unique_ptr<Item>);
	};
}
#endif
