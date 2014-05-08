#include "user.h"

namespace the_lion_king_saga {

	User::User(the_lion_king_saga::Environment* startPosition):
		_currentPosition(startPosition) {
#if DEBUG
			std::unique_ptr<Item> i(new Item("Coffeecup","HOT",1));
			_inventory[i->name()] = std::move(i);
			std::cout << _currentPosition->_description << " has nrNeighbors " << _currentPosition->_neighbors.size() << std::endl;
			std::cout << _currentPosition->getNeighbor(North)._description << " has nrNeighbors " << _currentPosition->getNeighbor(North)._neighbors.size() << std::endl;
			std::cout << _currentPosition->getNeighbor(North).getNeighbor(South)._description << " has nrNeighbors " << _currentPosition->getNeighbor(North).getNeighbor(South)._neighbors.size() << std::endl;
#endif
		}

	void User::list_actions() {
		std::cout << "Not implemented" << std::endl;
	}
	void User::look(std::string derections = NULL) {
		std::cout << "Not implemented" << std::endl;
	}
	void User::go(std::string s) {
		direction direction;
		if(s=="North") direction = North;
		if(s=="South") direction = South;
		if(s=="East") direction = East;
		if(s=="West") direction = West;
#if DEBUG
		std::cout << "Trying to walk " << s << direction << std::endl;
#endif
		Environment& e = _currentPosition->getNeighbor(direction);
		if(&e == 0){
			std::cout << "You're not able to walk " << s << std::endl;
		}
		else {
			std::cout << "You walked " << s << "into " << e._description << std::endl;
			_currentPosition = &e;
#if DEBUG
			std::cout << "Hej " << _currentPosition->_neighbors.size() << std::endl;
#endif
		}
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
}
