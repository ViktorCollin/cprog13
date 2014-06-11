#ifndef DJUNGLE_H
#define DJUNGLE_H

#include "environment.h"

namespace the_lion_king_saga {

    class Djungle : public Environment {

        protected:

        public:
            Djungle(std::string, std::string, std::string);

            std::unique_ptr<Item> getItem(std::string); 
    };
}

#endif
