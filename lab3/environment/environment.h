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
			//virtual std::map<std::string, std::string> directions() const = 0;
			Environment* getNeighbor(Direction);
			void addNeighbor(Environment*, Direction);
			void removeNeighbor(Direction);
			std::string description() const;
			std::string farAwayDescription() const;
			virtual void printDescription() const;
            void printDescription(Direction) const;
            void printAnimalsAndItems() const;

			void addAnimal(std::unique_ptr<Animal>);
            void removeAnimal(std::string);
			Animal* getAnimal(std::string);

			virtual std::unique_ptr<Item> getItem(std::string);
			void addItem(std::unique_ptr<Item>);
	};
}
#endif
