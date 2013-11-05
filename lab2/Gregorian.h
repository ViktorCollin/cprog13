#ifndef GREGORIAN_H
#define GREGORIAN_H
#include "Middle.h"

namespace lab2 {

  class Gregorian : Middle {
    private: 
      bool isLeepYear() const;

      void verifyDay();

    public:
      int year() const; 

      int month() const; 

      int day() const; 

      int week_day() const; 

      int days_per_week() const; 

      int days_this_month() const; 

      int months_per_year() const;

      std::string week_day_name() const; 

      std::string month_name() const;

  };

}
#endif

