#include <cstdio>
#include <string>
#include "Date.h"
#include <time.h>

namespace lab2 {

  Date::Date(){
    setCurrentDate(); 
  }

  Date::Date(int year, int month, int day) { 
    setDate(year, month, day);
  }

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
    return 7;
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

  void Date::add_month(int n) {
    int fac = -1;
    if( n > 0) fac = 1;
    _month += n;
    while(_month >= 13 || _month <= 0) {
      _month -= fac*12;
      _year += fac;
    }
    verifyDay();
  }

  void Date::verifyDay() {
    //TODO kolla skottår för februari
    if(_day > _daysOfMonth[_month - 1]) _day = _daysOfMonth[_month -1];
  }

  void Date::setCurrentDate() {
    time_t theTime = time(NULL);
    struct tm *aTime = localtime(&theTime);

    int day = aTime->tm_mday;
    int month = aTime->tm_mon + 1; // Month is 0 - 11, add 1 to get a jan-dec 1-12 concept
    int year = aTime->tm_year + 1900; // Year is # years since 1900

    setDate(year, month, day);
  }
  void Date::setDate(int year, int month, int day) {
    _day = day;
    _month = month;
    _year = year;
  }
}
