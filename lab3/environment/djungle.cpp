#include "djungle.h"

namespace the_lion_king_saga {

    Djungle::Djungle(std::string name, std::string description, std::string farAwayDescription):
        Environment(name, description, farAwayDescription) {}

    std::unique_ptr<Item> Djungle::getItem(std::string s) {
        auto i = new Item(*_items[s]);
        std::unique_ptr<Item> u_i(i);
        return u_i;
    }


}
