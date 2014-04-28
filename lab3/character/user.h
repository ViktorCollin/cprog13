#ifndef USER_H
#define USER_H

#include <map>
#include <string>
#include <iostream>

#include "animal.h"
#include "../item/item.h"
#include "../environment/environment.h"


namespace the_lion_king_saga {

	class User {
		protected:
			std::map<std::string,Item*> _inventory;
			the_lion_king_saga::Environment& _currentPosition;

		public:
			User(the_lion_king_saga::Environment&);
			void list_actions();
			void look(std::string);
			void go(std::string);
			void fight(std::string);
			void take(std::string);
			void drop(std::string);
			void talk_to(std::string);
			void showInventory();

	};
}
#endif
