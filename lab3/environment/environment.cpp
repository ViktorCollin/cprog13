#include <string>
#include <exception>

#include "environment.h"
#include "../item/item.h"

#define DEBUG 1

namespace the_lion_king_saga {

	Environment::Environment():_items(){}


	Item& Environment::get(std::string s) {
			Item *i = _items[s];
			_items.erase(s);
			return *i;
	}

	void Environment::add(Item& item) {
		_items[item.name()] = &item;
	}

	std::string Environment::description() const{
		return _description;
	}
	std::string Environment::shortDescription() const{
		return _shortDescription;
	}
}
