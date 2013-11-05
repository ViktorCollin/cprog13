#include <cstdio>
#include <string>
#include "Gregorian.h"
#include <time.h>

namespace lab2{

  Gregorian::Gregorian():Middle(){
  }
  Gregorian::Gregorian(int year, int month, int day):Middle(year,month,day){

  }
  int Gregorian::year() const {
    return 0;
  }

  int Gregorian::month() const {
    return 0;
  }

  int Gregorian::day() const {
    return 0;
  }

  int Gregorian::week_day() const {
    return 0;
  }

  int Gregorian::days_per_week() const {
    return 7;
  }

  int Gregorian::days_this_month() const {
    return 0;
  }

  int Gregorian::months_per_year() const {
    return 12;
  }

  std::string Gregorian::week_day_name() const {
    return NULL;
  }

  std::string Gregorian::month_name() const {
    return NULL;
  }

  Gregorian& Gregorian::add_year(int n) {
    return *this;
  }

  Gregorian& Gregorian::add_day(int n) {
    return *this;
  }

  void Gregorian::verifyDay() {
    //TODO kolla skottår för februari
    if(_day > _daysOfMonth[_month - 1]) _day = _daysOfMonth[_month -1];
  }

  void Gregorian::setCurrentDate() {
    time_t theTime = time(NULL);
    struct tm *aTime = localtime(&theTime);

    int day = aTime->tm_mday;
    int month = aTime->tm_mon + 1; // Month is 0 - 11, add 1 to get a jan-dec 1-12 concept
    int year = aTime->tm_year + 1900; // Year is # years since 1900

    setDate(year, month, day);
  }

  void Gregorian::setDate(int year, int month, int day) {
    unsigned long long days = 0;
    _days = days;
  }
  Gregorian& Gregorian::add_month(int n) {
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

  bool Gregorian::isLeapYear() const{
	return isLeapYear(year());
  }
  bool Gregorian::isLeapYear(int year) const{
      if (year % 400 == 0) return true; 
      if (year % 100 == 0) return false; 
      if (year % 4 == 0) return true; 
      return false;
  }
}
