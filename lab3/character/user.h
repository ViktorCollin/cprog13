#ifndef USER_H
#define USER_H

#include <map>
#include <string>
#include <iostream>
#include <memory>

#include "animal.h"
#include "enemy.h"
#include "../item/item.h"
#include "../environment/environment.h"
#include "../enums.cpp"


namespace the_lion_king_saga {

	class User : public Animal{
		protected:
			std::map<std::string,std::unique_ptr<Item>> _inventory;
			Environment* _currentPosition;

		public:
			User(Environment*);
			void list_actions() const;
			void look(std::string direction_s = "") const;
			void go(std::string);
			void fight(std::string);
			void take(std::string);
			void eat(std::string);
			void drop(std::string);
			void talk_to(std::string) const;
			void showInventory() const;
            Environment* currentPosition() const; 
            void newHealth(int);

			virtual void attack(Animal*);

	};
}
#endif
