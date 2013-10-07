#include <cstdio>
#include <string>

namespace lab2;
class Date {
  private int _year, _month, _day;

  Date() {
  
  }

  Date(int year, int month, int day): _year(year), _month(month), _day(day) { }

  int year() const {
    return _year;
  }

  int month() const {
    return _month;
  }

  int day() const {
    return _day;
  }

  int week_day() const {
    reutrn 0;
  }

  int days_per_week() const {
    return 0;
  }

  int days_this_month() const {
    return 0;
  }

  int months_per_year() const {
    return 0;
  }

  std::string week_day_name() const {
    return NULL;
  }

  std::string month_name() const {
    return NULL;
  }



}
