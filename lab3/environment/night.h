#ifndef NIGHT_H
#define NIGHT_H

#include "environment.h"

#include <string>

namespace the_lion_king_saga {

    class Night: public Environment {
        protected:

        public:
            Night(std::string,std::string,std::string);

            virtual void printDescription() const;
    };
}
#endif
