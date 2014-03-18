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
			void look();
			void go(std::string);
			void fight(Animal&);
			void pick_up(Item&);
			void drop(Item&);
			void talk_to(Animal&);


	};
}
#endif
