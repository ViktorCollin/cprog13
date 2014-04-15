#include <string>

#include "user.h"
#include "../item/item.h"

#define DEBUG 1

namespace the_lion_king_saga {

	User::User() {
#if DEBUG
		Item *i = new Item("Coffeecup","HOT",1);
		_inventory["Coffeecup"] = i;
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
		std::cout << "Not implemented" << std::endl;
	}
	void User::drop(std::string s) {
#if DEBUG
		std::cout << "Currently having " <<
			_inventory.size() << " items." << std::endl;
#endif
		if(_inventory.count(s)){
			Item *i = _inventory[s];
			_inventory.erase(s);
			delete i; //Or return to environment
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
