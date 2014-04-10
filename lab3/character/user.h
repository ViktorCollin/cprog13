#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>

#include "animal.h"
#include "../item/item.h"


namespace the_lion_king_saga {

	class User {
		protected:

		public:
			User();
			void list_actions();
			void look(std::string);
			void go(std::string);
			void fight(std::string);
			void take(std::string);
			void drop(std::string);
			void talk_to(std::string);


	};
}
#endif
