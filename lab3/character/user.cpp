#include <string>

#include "user.h"
#include "../item/item.h"
#include "../environment/environment.h"

#define DEBUG 1

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
	void User::take(std::string s) {
		_inventory[s] = &_currentPosition.get(s);
#if DEBUG
		std::cout << "Currently having " <<
			_inventory.size() << " items." << std::endl;
#endif
		std::cout << "Saknar lite validering här kanske :P" << std::endl;
	}
	void User::drop(std::string s) {
#if DEBUG
		std::cout << "Currently having " <<
			_inventory.size() << " items." << std::endl;
#endif
		if(_inventory.count(s)){
			Item *i = _inventory[s];
			std::cerr << i->name() << std::endl;
			_inventory.erase(s);
			std::cerr << i->name() << std::endl;
			_currentPosition.add(*i);	
			std::cout << "You dropped \"" + s + "\"" << std::endl;
		}
		else
			std::cout << "You do not have \""
				+ s + "\" in your inventory." << std::endl;

	}
	void User::talk_to(std::string s) {
		std::cout << "Not implemented" << std::endl;
	}
}
