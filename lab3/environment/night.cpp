#include "night.h"

namespace the_lion_king_saga  {

    Night::Night(std::string name, std::string description, std::string farAwayDescription):
        Environment::Environment(name, description, farAwayDescription) {
        }

    void Night::printDescription() const {
        std::cout << "The night is too dark to see everything" << std::endl;
    }
}
