#ifndef USER_H
#define USER_H

#include <map>
#include <string>
#include <iostream>
#include <memory>

#include "animal.h"
#include "../item/item.h"
#include "../environment/environment.h"
#include "../enums.cpp"


namespace the_lion_king_saga {

	class User : public Animal{
		protected:
			std::map<std::string,std::unique_ptr<Item>> _inventory;
			std::shared_ptr<Environment> _currentPosition;
            std::map<std::string, Direction> _mapDirections;

		public:
			User(std::shared_ptr<Environment>);
			void list_actions();
			void look(std::string direction_s = "");
			void go(std::string);
			void fight(std::string);
			void take(std::string);
			void drop(std::string);
			void talk_to(std::string);
			void showInventory();

			virtual int attack(Animal*);

	};
}
#endif
