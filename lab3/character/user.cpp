#include <string>

#include "user.h"
#include "../item/item.h"
#include "../environment/environment.h"

namespace the_lion_king_saga {

	User::User(the_lion_king_saga::Environment& startPosition):
		_currentPosition(startPosition) {
#if DEBUG
			Item *i = new Item("Coffeecup","HOT",1);
			_inventory[i->name()] = i;
#endif
		}

	void User::list_actions() {
		std::cout << "Not implemented" << std::endl;
	}
	void User::look(std::string derections = NULL) {
		std::cout << "Not implemented" << std::endl;
	}
	void User::go(std::string s) {
		std::cout << "Not implemented" << std::endl;
	}
	void User::fight(std::string s) {
		std::cout << "Not implemented" << std::endl;
	}
	void User::showInventory() {
		std::cout << "Currently in your inventory:" << std::endl;
		for(auto imap: _inventory) {
			std::cout << imap.first << std::endl;
		}
	}
	void User::take(std::string s) {
		Item& item = _currentPosition.get(s);
		if(&item == 0)
			std::cout << "No item with the name \"" <<
				s << "\" exists" << std::endl;
		else {
			_inventory[s] = &item;
			std::cout << "Picked up \"" << s << "\"" << std::endl;
		}
#if DEBUG
		std::cout << "Currently having " <<
			_inventory.size() << " items." << std::endl;
#endif
	}
	void User::drop(std::string s) {
		if(_inventory.count(s)){
			Item *i = _inventory[s];
			_inventory.erase(s);
			_currentPosition.add(*i);	
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
