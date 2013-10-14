#ifndef DATE_H
#define DATE_H
#include <string>



namespace lab2 {

  class Date {
    private: 
      long _days;
      int _day, _month, _year;
      int _daysOfMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

      void setCurrentDate();

      void setDate(int, int, int);

      void verifyDay();
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

      void add_month(int n = 1);
  };
}
#endif
