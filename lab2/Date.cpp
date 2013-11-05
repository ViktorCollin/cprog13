#include <cstdio>
#include <string>
#include "Date.h"
#include <time.h>

namespace lab2 {

  Date::Date(){
  }
  Date::Date(int y,int m,int d){
  }
  Date::Date(unsigned long long days): _days(days) {};
  
  Date::Date(const Date& d){
    if(this == &d) return;
    _days = d.getDays();
  }
}
