#include "user.h"

namespace the_lion_king_saga {

    User::User(std::shared_ptr<Environment> startPosition): Animal::Animal("Simba", 100),
    _currentPosition(startPosition) {
#if DEBUG
        std::unique_ptr<Item> i(new Item("Coffeecup","HOT",1, true));
        _inventory[i->name()] = std::move(i);
#endif
    }

    void User::look(std::string direction_s /* = "" */) {
        //This needs to handle different types of rooms
        if(direction_s=="") {
            _currentPosition->printDescription();
        } else {
            std::cout << "Not implemented" << std::endl;
        }
    }
    void User::go(std::string s) {
        Direction dir = strToDirection(s);
#if DEBUG
        std::cout << "Trying to walk " << s << " (" << dir << ")" << std::endl;
#endif
        if(dir == INVALID_DIRECTION){
            std::cout << s << " is NOT a vaild direction, try one of " << listDirections() <<std::endl;
            return;
        }
        std::shared_ptr<Environment> e = _currentPosition->getNeighbor(dir);
        if(e == NULL){
            std::cout << "You're not able to walk " << s << std::endl;
            return;
        }
        _currentPosition = e;
        std::cout << "You walked " << s << " into " << _currentPosition->name() << std::endl;	
    }
    void User::fight(std::string s) {
        Animal* a = _currentPosition->getAnimal(s);
        if(a == 0)
            std::cout << "No animal named " << s << " could be found" << std::endl;
        else
            User::attack(a);
    }
    void User::showInventory() {
        std::cout << "Currently in your inventory:" << std::endl;
        for(auto& imap: _inventory) {
            std::cout << imap.first << std::endl;
        }
    }
    void User::use(std::string s) {
        if(_inventory.count(s)) {
            if(_inventory[s].get()->isUsable()){
                _inventory[s].get()->use();	
                std::cout << "You used \"" + s + "\"" << std::endl;
            } else{
                std::cout << "This item is not usable" << std::endl;
            }
        } else {
            std::cout << "You do not have " << s << std::endl;
        }
    }
    void User::take(std::string s) {
        std::unique_ptr<Item> item(_currentPosition->get(s));
        if(item == 0)
            std::cout << "No item with the name \"" <<
                s << "\" exists" << std::endl;
        else {
            _inventory[s] = std::move(item);
            std::cout << "Picked up \"" << s << "\"" << std::endl;
        }
#if DEBUG
        std::cout << "Currently having " <<
            _inventory.size() << " items." << std::endl;
#endif
    }
    void User::drop(std::string s) {
        if(_inventory.count(s)){
            _currentPosition->add(std::move(_inventory[s]));	
            _inventory.erase(s);
            std::cout << "You dropped \"" + s + "\"" << std::endl;
        }
        else
            std::cout << "You do not have \""
                + s + "\" in your inventory." << std::endl;
#if DEBUG
        std::cout << "Currently having " <<
            _inventory.size() << " items." << std::endl;
#endif

    }
    void User::talk_to(std::string s) {
        std::cout << "Not implemented" << std::endl;
    }

    void  User::attack(Animal* a) {
        int damage = 60;
        std::cout << "Attacking " << a->name() << std::endl;
        if(a->isDead()) damage = 0;
        std::cout << "Did " << damage << " damage and " << a->name() << "'s health is now " << a->health(damage) << std::endl;
        if(a->isDead()) {
            std::cout << "The only thing left is " << a->name() << std::endl;
        } else {
            a->attack(this);
        }
    }
}
