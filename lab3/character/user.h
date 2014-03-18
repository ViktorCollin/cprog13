#ifndef USER_H
#define USER_H

namespace the_lion_king_saga {

	class User {
		protected:

		public:
			void list_actions();
			void look();
			void go(std::String);
			void fight(Animal);
			void pick_up(Item);
			void drop(Item);
			void talk_to(Animal);


	}
}
#endif
