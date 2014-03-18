#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

namespace the_lion_king_saga {

	class Environment {
		protected:

		public:
			Environment();

			virtual std::vector<std::String> derections() const;
			virtual Environment neighbor(std::String);
			virtual std::String description() const;
			virtual void enter(Animal);
			virtual void leave(Animal);

			void remove(Item);
			void add(Item);
	}

#endif
