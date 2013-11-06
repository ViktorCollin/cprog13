#include <cstdio>
#include <string>
#include "Gregorian.h"
#include <time.h>
#include <stdexcept>

namespace lab2{

    Gregorian::Gregorian():Middle(){
    }
    Gregorian::Gregorian(int year, int month, int day):Middle(year,month,day){
        if(month < 1 || month > 12 || day < 1 || day > days_month(year, month))
            throw std::out_of_range("The date imported is not valid");
        set_date(year,month,day);
    }
    Gregorian::Gregorian(unsigned long long numeric):Middle(numeric){

    }
    Gregorian::Gregorian(const Date& d):Middle(d){

    }

    Gregorian Gregorian::operator++(int i) {
        Gregorian g(*this);
        _numeric++;
        return g;
    }

    Gregorian Gregorian::operator--(int i) {
        Gregorian g(*this);
        _numeric--;
        return g;
    }

    int Gregorian::year() const {
        if(calculatedDate != _numeric) calcYMD();
        return _year;
    }

    int Gregorian::month() const {
        if(calculatedDate != _numeric) calcYMD();
        return _month;
    }

    int Gregorian::day() const {
        if(calculatedDate != _numeric) calcYMD();
        return _day;
    }

    inline int Gregorian::week_day() const {
        return _numeric % days_per_week() + 1;
    }

    int Gregorian::months_per_year() const {
        return 12;
    }

    inline int Gregorian::days_per_week() const {
        return 7;
    }

    int Gregorian::days_month(int y, int m) const{
        while(m > 12) { m -= 12; y++; }
        while(m < 1) { m += 12; y--; }
        if(isLeapYear(y) && m == 2) return 29;
        return _daysOfMonth[m-1];
    }

    int Gregorian::days_this_month() const {
        return days_month(year(), month());

    }

    std::string Gregorian::week_day_name() const {
        return nameOfMonth[week_day()-1];
    }

    std::string Gregorian::month_name() const {
        return nameOfMonth[month()-1];
    }

    Gregorian& Gregorian::add_year(int n) {
        if(n == 0) return *this;
        int sign = -1;
        if( n > 0)  {
            sign = 1;
        }

        if(isLeapYear()) {
            if(std::abs(n) % 4 == 0) {
                _numeric += (365*4 + 1 )*sign;
                n -= sign * 4;
                return add_year(n);
            }else if((sign > 0 && (month() < 3 && !(month() == 2 && day() == 29 ))) ||
                    (sign < 0 && month() > 3 )) {
                _numeric += 366 * sign;
                n -= sign;
                return add_year(n);
            }
        } else if(isLeapYear(year() + sign) && (( month() > 3 && sign > 0) ||
                    (sign < 0 && (month() < 3 )))) {
            _numeric += 366 * sign;
            n -= sign;
            return add_year(n);
        }
        _numeric += 365 * sign;
        n -= sign;
        return add_year(n);
    }

    Gregorian& Gregorian::add_month(int n) {
        int sign = -1;
        if( n > 0)  {
            sign = 1;
        }
        n = std::abs(n);
        for(int i = 0; i < n; ++i) {
            if(days_month(year(), month() + sign) < day()){
                _numeric += 30 * sign;
            } else if(sign > 0) {
                _numeric += days_this_month();
            } else {
                _numeric -= days_month(year(), month()-1);
            }
        }
        return *this;
    }

    Gregorian& Gregorian::add_day(int n) {
        _numeric += n;
        return *this;
    }

    void Gregorian::calcYMD() const{
        int y = 4716, j = 1401, m = 2, n = 12, r = 4, p = 1461, v = 3, u = 5,
            s = 153, w = 2, B = 274277, C = -38;
        unsigned long long f = _numeric + j + (((4 * _numeric + B)/146097)*3)/4+C;
        unsigned long long e = r * f + v;
        unsigned int g = (e % p) /r;
        unsigned int h = u * g + w;
        _day = (h % s)/u + 1;
        _month = ((h/s + m) % n) + 1;
        _year = e/p - y + (n+m - _month)/n;
    }

    unsigned long long Gregorian::YMDtoNumeric(int year, int month, int day) const{
        int a = (14 - month)/12; 
        int y = year + 4800 - a;
        int m = month + 12*a - 3;
        return day + (153*m + 2)/5 + 365*y + y/4 - y/100 + y/400 - 32045;
    }

    void Gregorian::setCurrentDate() {
        time_t theTime = time(NULL);
        struct tm *aTime = localtime(&theTime);

        int day = aTime->tm_mday;
        int month = aTime->tm_mon + 1; // Month is 0 - 11, add 1 to get a jan-dec 1-12 concept
        int year = aTime->tm_year + 1900; // Year is # years since 1900

        setDate(year, month, day);
    }

    void Gregorian::setDate(int year, int month, int day) {
        _numeric = YMDtoNumeric(year, month, day);
        _year = year;
        _month = month;
        _day = day;
        calculatedDate = _numeric;
    }

    void Gregorian::set_date(int y, int m, int d)  {
        setDate(y,m,d);
    }


    bool Gregorian::isLeapYear() const{
        return isLeapYear(year());
    }
    bool Gregorian::isLeapYear(int year) const{
        if (year % 400 == 0) return true; 
        if (year % 100 == 0) return false; 
        if (year % 4 == 0) return true; 
        return false;
    }
}
