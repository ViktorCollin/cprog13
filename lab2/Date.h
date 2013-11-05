#ifndef DATE_H
#define DATE_H
#include <string>



namespace lab2 {

  class Date {
    private: 
      long _days;

      void setCurrentDate();

    public:
      Date();

      virtual int year() const = 0;

      virtual int month() const = 0;

      virtual int day() const = 0;

      virtual int week_day() const = 0;

      virtual int days_this_month() const = 0;

      virtual int months_per_year() const = 0;

      virtual std::string week_day_name() const = 0;

      virtual std::string month_name() const = 0;

      //Operators
      Date& operator++();
      Date& operator--();
      Date& operator+=();
      Date& operator-=();

      Date& add_year(n = 1);
      Date& add_month(n = 1);
      Date& add_day(n = 1);

      bool operator==(const Date&) const; 
      bool operator!=(const Date&) const; 
      bool operator<(const Date&) const; 
      bool operator<=(const Date&) const; 
      bool operator>(const Date&) const; 
      bool operator>=(const Date&) const; 
      bool operator-(const Date&); 

      long mod_julian_day() const;
  };
}
#endif
