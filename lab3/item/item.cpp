#include "item.h"

namespace the_lion_king_saga {

    Item::Item(std::string name, std::string description, int weight, bool usable):
        _name(name), _description(description), _weight(weight), _usable(usable), _status() {}

    Item::Item(std::string name, std::string description, int weight):
        _name(name), _description(description), _weight(weight), _usable(false), _status() {}

    std::string Item::name() const {
        return _name;
    }

    std::string Item::description() const {
        return _description;
    }

    std::string Item::status() const {
        if(_status.empty()) {
            return "";
        }
        std::string status;
        std::set<std::string>::iterator it=_status.begin();
        status.append( "(" + *it);
        auto nx = std::next(it, 1);
        for(; nx!=_status.end(); ++nx) {
            status.append(", " + *nx);
        }
        status.append(")");
        return status;
    }

    int Item::weight() const {
        return _weight;
    }

    bool Item::isUsable() const {
        return _usable;
    }   

    void Item::addStatus(const std::string& s) {
        _status.insert(s);
    }

    void Item::removeStatus(const std::string& s) {
        _status.erase(s);
    }

    void Item::use() {
        _usable = false;
    }
}
