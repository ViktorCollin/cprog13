#include "item.h"

#include <string>

namespace the_lion_king_saga {

	Item::Item(std::string name, std::string description, int weight):
		_name(name), _description(description), _weight(weight) {}

	std::string Item::name() const {
		return _name;
	}

	std::string Item::description() const {
		return _description;
	}

	int Item::weight() const {
		return _weight;
	}

}
