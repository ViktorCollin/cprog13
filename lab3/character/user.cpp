#include "user.h"

namespace the_lion_king_saga {

	User::User(std::shared_ptr<Environment> startPosition): Animal::Animal("simba", 1000),
	_currentPosition(startPosition) {
            _mapDirections["North"] = North;
            _mapDirections["South"] = South;
            _mapDirections["East"] = East;
            _mapDirections["West"] = West;
#if DEBUG
		std::unique_ptr<Item> i(new Item("Coffeecup","HOT",1));
		_inventory[i->name()] = std::move(i);
		std::cout << _currentPosition->description ()<< " has nrNeighbors " << _currentPosition->_neighbors.size() << std::endl;
		std::cout << _currentPosition->getNeighbor(North)->description() << " has nrNeighbors " << _currentPosition->getNeighbor(North)->_neighbors.size() << std::endl;
		std::cout << _currentPosition->getNeighbor(North)->getNeighbor(South)->description() << " has nrNeighbors " << _currentPosition->getNeighbor(North)->getNeighbor(South)->_neighbors.size() << std::endl;
#endif
	}

	void User::list_actions() {
		std::cout << "Not implemented" << std::endl;
	}
	void User::look(std::string direction_s /* = "" */) {
		if(direction_s=="") {
			std::cout << _currentPosition->description() << std::endl;
		} else {
			std::cout << "Not implemented" << std::endl;
		}
	}
	void User::go(std::string s) {
        Direction dir = strToDirection(s);
#if DEBUG
		std::cout << "Trying to walk " << s << " (" << dir << ")" << std::endl;
#endif
        if(dir == 0){
            std::cout << s << " is NOT a vaild direction, try one of " <<std::endl;
            for(auto& imap: _mapDirections) {
    			std::cout  << imap.first << std::endl;
    		}
            return;
        }
		std::shared_ptr<Environment> e = _currentPosition->getNeighbor(dir);
		if(e == NULL){
			std::cout << "You're not able to walk " << s << std::endl;
            return;
		}
		_currentPosition = e;
		std::cout << "You walked " << s << "into " << _currentPosition->description() << std::endl;	
#if DEBUG
		std::cout << "Welcome " << _currentPosition->_neighbors.size() << std::endl;
#endif
	}
	void User::fight(std::string s) {
		std::cout << "Not implemented" << std::endl;
	}
	void User::showInventory() {
		std::cout << "Currently in your inventory:" << std::endl;
		for(auto& imap: _inventory) {
			std::cout << imap.first << std::endl;
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

	int  User::attack(Animal* a) {
		std::cout << "No attack implemented for simba" << std::endl;
	}
}
