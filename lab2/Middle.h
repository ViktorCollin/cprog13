#include "Date.h"

namespace lab2 {

  class Middle : Date {
    private :
      int _daysOfMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
      int _day = -1, _month = -1, _year = -1;
  };
}

