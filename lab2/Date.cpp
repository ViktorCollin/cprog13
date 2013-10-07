#include <cstdio>
#include <string>
#include "Date.h"

namespace lab2 {

  Date::Date():_year(0), _month(0), _day(0) { }

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

}
