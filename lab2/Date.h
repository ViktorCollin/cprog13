#ifndef DATE_H
#define DATE_H
#include <string>



namespace lab2 {

  class Date {
    private: 
      int _year, _month, _day;

      void currentDate();

    public:
      Date();

      Date(int, int, int);

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
