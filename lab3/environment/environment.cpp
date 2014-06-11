#include "environment.h"

namespace the_lion_king_saga {

    Environment::Environment(std::string name, std::string description, std::string farAwayDescription):
        _items(), 
        _neighbors(), 
        _animals(),
        _name(name),
        _description(description), 
        _farAwayDescription(farAwayDescription) {}

    std::string Environment::name() {
        return _name;
    }

    std::unique_ptr<Item> Environment::getItem(std::string s) {
        std::unique_ptr<Item> i = std::move(_items[s]);
        _items.erase(s);
        return i;
    }

    //Will return address 0 if not found
    Environment* Environment::getNeighbor(Direction d) {
        auto it = _neighbors.find(d);
        if(it == _neighbors.end()) return NULL;
        return it->second;
    }
    void Environment::addItem(std::unique_ptr<Item> item) {
        _items[item->name()] = std::move(item);
    }

    void Environment::addNeighbor(Environment* e, Direction d) {
        _neighbors[d] = e;
    }
    void Environment::printDescription() const{
        std::cout << _description << std::endl;
        for(auto& imap: _neighbors) {
            std::cout << "\tTo the " << directionToStr(imap.first) << " " << imap.second->farAwayDescription() << std::endl;
        }
    }

    void Environment::printDescription(Direction dir) const{
        auto env = _neighbors.find(dir);
        if(env == _neighbors.end()) {
            std::cout << "There is nothing to the " << directionToStr(dir) << std::endl;
        } else {
            std::cout << "\tTo the " << directionToStr(dir) << " " << env->second->farAwayDescription() << std::endl;
        }
    }

    void Environment::printAnimalsAndItems() const {
        if(!_animals.empty()) {
            std::cout << "There are other animals here:" << std::endl;
            for(auto& imap: _animals) {
                std::cout << "\t" << imap.first << std::endl;

            }
        }
        if(!_items.empty()) {
            std::cout << "There are things here:" << std::endl;
            for(auto& imap: _items) {
                std::cout << "\t" <<  imap.first << std::endl;

            }
        }
    }

    std::string Environment::description() const{
        return _description;
    }
    std::string Environment::farAwayDescription() const{
        return _farAwayDescription;
    }
    void Environment::addAnimal(std::unique_ptr<Animal> animal) {
        _animals[animal->name()] = std::move(animal);
    }

    Animal* Environment::getAnimal(std::string s) {
        Animal* a = NULL;
        if(_animals.count(s)>0){
            a = _animals[s].get();
        }
        return a;
    }
}
