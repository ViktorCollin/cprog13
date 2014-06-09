#include "breakable.h"

#include <string>

namespace the_lion_king_saga {

    Breakable::Breakable(std::string name, std::string description, int weight):
        Item::Item(name, description, weight, true) {}

    void Breakable::use() {
        Item::addStatus("Broken");
        _usable = false;
    }
}
