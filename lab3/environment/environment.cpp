#include "environment.h"

namespace the_lion_king_saga {

	Environment::Environment(std::string description):_items(), _neighbors(), _description(description) {}


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
		return _description;
	}
	std::string Environment::shortDescription() const{
		return _shortDescription;
	}
}
