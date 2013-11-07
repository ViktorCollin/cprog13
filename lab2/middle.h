#ifndef MIDDLE_H
#define MIDDLE_H
#include "date.h"

namespace lab2{

  class Middle : public Date {

    protected:
      static const int _daysOfMonth[]; 
      static const std::string nameOfDay[];
      static const std::string nameOfMonth[];

      mutable unsigned long long calculatedDate; 
      mutable int _day, _month, _year;
      
      bool isLeapYear() const;
      virtual bool isLeapYear(int) const = 0;
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
      int months_per_year() const;
      int days_per_week() const;
      int days_month(int, int) const;
      int days_this_month() const;  
      std::string week_day_name() const; 
      std::string month_name() const;

      Middle& add_year(int n = 1);
      Middle& add_month(int n = 1);
      Middle& add_day(int n = 1);
      
      void set_date(int, int, int);
  };
  
  //std::ostream & operator<<(std::ostream &, const Middle&);
}
#endif

