#include "environment.h"

namespace the_lion_king_saga {

	void Environment::remove(Item& item) {
		std::cout << "Not implemented" << std::endl;
	}

	void Environment::add(Item& item) {
		std::cout << "Not implemented" << std::endl;
	}
	
	std::string Environment::description() const{
        return _description;
	}
	std::string Environment::shortDescription() const{
	    return _shortDescription;
	}
}
