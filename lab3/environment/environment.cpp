#include "environment.h"

namespace the_lion_king_saga {

	Environment::Environment():_items(), _neighbors() {}


	Item& Environment::get(std::string s) {
			Item *i = _items[s];
			_items.erase(s);
			return *i;
	}

	//Will return address 0 if not found
	Environment& Environment::getNeighbor(direction d) {
		return *_neighbors[d];
	}
	void Environment::add(Item& item) {
		_items[item.name()] = &item;
	}

	void Environment::addNeighbor(Environment& e, direction d) {
		_neighbors[d] = &e;
	}
	std::string Environment::description() const{
		return _description;
	}
	std::string Environment::shortDescription() const{
		return _shortDescription;
	}
}
