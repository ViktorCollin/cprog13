#ifndef EATABLE_H
#define EATABLE_H

#include <string>
#include "item.h"

namespace the_lion_king_saga {

    class Eatable : public Item {
        protected:
        public:
            Eatable(std::string, std::string, int);
            Eatable(const Item&);

            virtual void eat();

    };
}
#endif
