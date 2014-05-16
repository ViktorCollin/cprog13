#ifndef DAY_H
#define DAY_H

#include "environment.h"

#include <string>

namespace the_lion_king_saga {

  class Day : public Environment {
    protected:

    public:
      Day(std::string, std::string, std::string);
      std::map<std::string, std::string> directions() const;
      Environment& neighbor(std::string);

      void enter(Animal&);
      void leave(Animal&);
  };
}
#endif
