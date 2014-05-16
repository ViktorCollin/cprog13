#include "environment.h"

namespace the_lion_king_saga {

	Environment::Environment(std::string description):_items(), _neighbors(), _animals() ,_description(description) {}


	std::unique_ptr<Item> Environment::get(std::string s) {
		std::unique_ptr<Item> i = std::move(_items[s]);
		_items.erase(s);
		return i;
	}

	//Will return address 0 if not found
	std::shared_ptr<Environment> Environment::getNeighbor(direction d) {
		return _neighbors[d];
	}
	void Environment::add(std::unique_ptr<Item> item) {
		_items[item->name()] = std::move(item);
	}

	void Environment::addNeighbor(std::shared_ptr<Environment> e, direction d) {
		_neighbors[d] = e;
	}
	std::string Environment::description() const{
		if(!_animals.empty()) {
			std::cout << "There are other animals here:" << std::endl;
			for(auto& imap: _animals) {
				std::cout << imap.first << std::endl;

			}
		}
		return _description;
	}

	std::string Environment::shortDescription() const{
		return _shortDescription;
	}

	void Environment::addAnimal(std::unique_ptr<Animal> animal) {
		_animals[animal->name()] = std::move(animal);
	}
}
