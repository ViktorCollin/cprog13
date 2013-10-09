#include <cstdio>
#include <string>
#include "Date.h"
#include <time.h>

namespace lab2 {

  Date::Date(){
    currentDate(); 
  }

  Date::Date(int year, int month, int day): _year(year), _month(month), _day(day) { }

  int Date::year() const {
    return _year;
  }

  int Date::month() const {
    return _month;
  }

  int Date::day() const {
    return _day;
  }

  int Date::week_day() const {
    return 0;
  }

  int Date::days_per_week() const {
    return 0;
  }

  int Date::days_this_month() const {
    return 0;
  }

  int Date::months_per_year() const {
    return 0;
  }

  std::string Date::week_day_name() const {
    return NULL;
  }

  std::string Date::month_name() const {
    return NULL;
  }

  void Date::currentDate() {
    time_t theTime = time(NULL);
    struct tm *aTime = localtime(&theTime);

    _day = aTime->tm_mday;
    _month = aTime->tm_mon + 1; // Month is 0 - 11, add 1 to get a jan-dec 1-12 concept
    _year = aTime->tm_year + 1900; // Year is # years since 1900
  }
}
