#ifndef MIDDLE_H
#define MIDDLE_H
#include "Date.h"

namespace lab2{

  class Middle : public Date {

    protected:
      const int _daysOfMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
      const std::string nameOfDay[7] = {"monday", "tuesday",
          "wednesday", "thursday", "friday", "saturday", "sunday"};
      const std::string nameOfMonth[12] = {"january", "february",
          "march", "april", "may", "june", "july", "august",
          "september", "october", "november", "december"};
      mutable unsigned long long calculatedDate; 
      mutable int _day, _month, _year;
      virtual void calcYMD() const = 0;
      virtual unsigned long long YMDtoNumeric(int, int, int) const = 0;

    public: 
      Middle();
      Middle(int, int, int);
      Middle(unsigned long long);
      Middle(const Date&);
       
      int year() const; 
      int month() const; 
      int day() const; 
      int week_day() const; 
      inline int months_per_year() const;
      inline int days_per_week() const;
      int days_month(int, int) const;
      int days_this_month() const;  
      std::string week_day_name() const; 
      std::string month_name() const;

      virtual Middle& add_year(int n = 1) = 0;
      virtual Middle& add_month(int n = 1) = 0;
      virtual Middle& add_day(int n = 1) = 0;
      
      virtual void set_date(int, int, int) = 0;
  };
}
#endif

