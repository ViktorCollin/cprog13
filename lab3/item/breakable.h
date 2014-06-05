#ifndef BREAKABLE_H
#define BREAKABLE_H

#include <string>
#include "item.h"

namespace the_lion_king_saga {

    class Breakable : public Item {
        protected:
        public:
            Breakable(std::string, std::string, int);

            virtual void use();

    };
}
#endif
