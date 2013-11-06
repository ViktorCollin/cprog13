#ifndef GREGORIAN_H
#define GREGORIAN_H
#include "Middle.h"

namespace lab2{

  class Gregorian : public Middle {
    protected: 
      bool isLeapYear() const;
      bool isLeapYear(int) const;

      void verifyDay();

      void setDate(int, int,int);

      void setCurrentDate();
    public:
      Gregorian();
      Gregorian(int,int,int);
      Gregorian(unsigned long long);
      Gregorian(const Date&);
      
      virtual Gregorian operator++(int);
      virtual Gregorian operator--(int); 

      virtual int year() const; 
      virtual int month() const; 
      virtual int day() const; 
      virtual int week_day() const; 
      virtual int days_per_week() const; 
      virtual int days_this_month() const; 
      virtual int months_per_year() const;
      virtual int days_month(int,int) const;
      virtual std::string week_day_name() const; 
      virtual std::string month_name() const;

      virtual Gregorian& add_year(int n = 1);
      virtual Gregorian& add_month(int n = 1);
      virtual Gregorian& add_day(int n = 1);

      virtual void set_date(int,int,int);

      void calcYMD() const; 
      unsigned long long YMDtoNumeric(int,int,int) const; 
  };

}
#endif

