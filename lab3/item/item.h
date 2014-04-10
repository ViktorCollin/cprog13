#ifndef ITEM_H
#define ITEM_H

#include <string>

namespace the_lion_king_saga {

	class Item {
		protected:
			std::string _name;
			std::string _description;
			int _weight;
		public:
			Item(std::string, std::string, int);
			std::string name() const;
			std::string description() const;
			int weight() const;

	};
}
#endif
