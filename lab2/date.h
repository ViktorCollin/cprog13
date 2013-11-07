#ifndef DATE_H
#define DATE_H
#include <string>
#include <iostream>


namespace lab2 {

    class Date {
        protected: 
            unsigned long long _numeric;


        public:
            Date();
            Date(int,int,int);
            Date(unsigned long long);
            Date(const Date&);

            virtual int year() const = 0;
            virtual int month() const = 0;
            virtual int day() const = 0;
            virtual int week_day() const = 0;
            virtual int days_per_week() const = 0;
            virtual int days_this_month() const = 0;
            virtual int months_per_year() const = 0;
            virtual std::string week_day_name() const = 0;
            virtual std::string month_name() const = 0;

            //Operators
            Date& operator=(const Date&);
            //Date& operator=(Date&&);

            Date& operator++();
            Date& operator--();

            Date& operator+=(const Date&);
            Date& operator-=(const Date&);

            long operator-(const Date&) const;

            virtual Date& add_year(int n = 1) = 0;
            virtual Date& add_month(int n = 1) = 0;
            virtual Date& add_day(int n = 1) = 0;

            bool operator==(const Date&) const; 
            bool operator!=(const Date&) const; 
            bool operator<(const Date&) const; 
            bool operator<=(const Date&) const; 
            bool operator>(const Date&) const; 
            bool operator>=(const Date&) const; 

            unsigned long long getNumeric() const;
            long mod_julian_day() const;
    };
    std::ostream & operator<<(std::ostream &, const Date&);
}
#endif
