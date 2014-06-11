#include "eatable.h"

#include <string>

namespace the_lion_king_saga {

    Eatable::Eatable(std::string name, std::string description, int weight):
        Item::Item(name, description, weight, true) {}

    Eatable::Eatable(const Item& i):
        Item::Item(i) {}
        

    void Eatable::eat() {
        addStatus("Eaten");
        _usable = false;
        _weight = 0;
    }
}
