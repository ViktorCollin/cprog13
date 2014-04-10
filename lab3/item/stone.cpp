#include "stone.h"

#include <string>

namespace the_lion_king_saga {

	Stone::Stone(std::string _name, std::string _description, int _weight):
		Item::Item(_name, _description, _weight) {}

}
