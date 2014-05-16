#include "day.h"

namespace the_lion_king_saga {

  Day::Day(std::string name, std::string description):
	  Environment::Environment(name, description){}

  std::map<std::string, std::string> Day::directions() const{
    std::map<std::string, std::string> s;
    return s;
  }
  Environment& Day::neighbor(std::string){
    return *this;
  }

  void Day::enter(Animal&){

  }
  void Day::leave(Animal&){

  }
}
