#include <cstdio>
#include <string>
#include "Julian.h"
#include <time.h>

namespace lab2{

  Julian::Julian():Middle(){
  }
  Julian::Julian(int year, int month, int day){

  }
  int Julian::year() const {
    return 0;
  }

  int Julian::month() const {
    return 0;
  }

  int Julian::day() const {
    return 0;
  }

  int Julian::week_day() const {
    return 0;
  }

  int Julian::days_per_week() const {
    return 7;
  }

  int Julian::days_this_month() const {
    return 0;
  }

  int Julian::months_per_year() const {
    return 12;
  }

  std::string Julian::week_day_name() const {
    return NULL;
  }

  std::string Julian::month_name() const {
    return NULL;
  }

  Julian& Julian::add_year(int n) {
    return *this;
  }

  Julian& Julian::add_day(int n) {
    return *this;
  }

  void Julian::verifyDay() {
    //TODO kolla skottår för februari
    if(_day > _daysOfMonth[_month - 1]) _day = _daysOfMonth[_month -1];
  }

  void Julian::setCurrentDate() {
    time_t theTime = time(NULL);
    struct tm *aTime = localtime(&theTime);

    int day = aTime->tm_mday;
    int month = aTime->tm_mon + 1; // Month is 0 - 11, add 1 to get a jan-dec 1-12 concept
    int year = aTime->tm_year + 1900; // Year is # years since 1900

    setDate(year, month, day);
  }

  void Julian::setDate(int year, int month, int day) {
    unsigned long long days = 0;
    _numeric = days;
  }
  Julian& Julian::add_month(int n) {
    int fac = -1;
    if( n > 0) fac = 1;
    _month += n;
    while(_month >= 13 || _month <= 0) {
      _month -= fac*12;
      _year += fac;
    }
    verifyDay();
    return *this;
  }

  void Julian::set_date(int y, int m, int d) {
      setDate(y,m,d);
  }

  bool Julian::isLeapYear() const{
    return false;
  }
}
