#ifndef MIDDLE_H
#define MIDDLE_H
#include "Date.h"

namespace lab2{

  class Middle : public Date {

    protected :
      const int _daysOfMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
      const std::string nameOfDay[7] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
      const std::string nameOfMonth[12] = {"january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};
      mutable unsigned long long calculatedDate; 
      mutable int _day, _month, _year;

    public : 
      Middle();
      Middle(int, int, int);
      Middle(unsigned long long);
      Middle(const Date&);

      virtual int year() const = 0; 
      virtual int month() const = 0; 
      virtual int day() const = 0; 
      virtual int week_day() const = 0; 
      virtual int days_per_week() const = 0; 
      virtual int days_this_month() const = 0; 
      virtual int months_per_year() const = 0;
      virtual std::string week_day_name() const = 0; 
      virtual std::string month_name() const = 0;

      virtual Middle& add_year(int n = 1) = 0;
      virtual Middle& add_month(int n = 1) = 0;
      virtual Middle& add_day(int n = 1) = 0;
      
  };
}
#endif

