#ifndef JULIAN_H
#define JULIAN_H
#include "Middle.h"

namespace lab2{

  class Julian : public Middle {
    protected: 
      bool isLeapYear() const;

      void verifyDay();

      void setDate(int, int,int);

      void setCurrentDate();
    public:
      Julian();
      Julian(int,int,int);
      
      virtual int year() const; 

      virtual int month() const; 

      virtual int day() const; 

      virtual int week_day() const; 

      virtual int days_per_week() const; 

      virtual int days_this_month() const; 

      virtual int months_per_year() const;

      virtual std::string week_day_name() const; 

      virtual std::string month_name() const;

      virtual Julian& add_year(int n = 1);
      virtual Julian& add_month(int n = 1);
      virtual Julian& add_day(int n = 1);

      virtual void set_date(int,int,int);
  };

}
#endif

