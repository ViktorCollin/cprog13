#ifndef GREGORIAN_H
#define GREGORIAN_H
#include "Middle.h"
#include <iomanip>


namespace lab2{

  class Gregorian : public Middle {
    protected: 
      bool isLeapYear() const;
      bool isLeapYear(int) const;

      void setDate(int, int,int);

      void setCurrentDate();

      void calcYMD() const; 
      unsigned long long YMDtoNumeric(int,int,int) const; 

    public:
      Gregorian();
      Gregorian(int,int,int);
      Gregorian(unsigned long long);
      Gregorian(const Date&);
      
      Gregorian operator++(int);
      Gregorian operator--(int);

      int year() const; 
      int month() const; 
      int day() const; 
      int week_day() const; 
      int days_per_week() const; 
      int days_this_month() const; 
      int months_per_year() const;
      int days_month(int,int) const;
      std::string week_day_name() const; 
      std::string month_name() const;

      Gregorian& add_year(int n = 1);
      Gregorian& add_month(int n = 1);
      Gregorian& add_day(int n = 1);

      void set_date(int,int,int);

  };
  
  std::ostream & operator<<(std::ostream &, const Gregorian&);

}
#endif

