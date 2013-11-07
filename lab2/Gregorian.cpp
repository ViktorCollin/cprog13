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

    //Gregorian Gregorian::operator-(const Date& d) const{
        //return Gregorian(_numeric - d.getNumeric());
    //}

    //Gregorian Gregorian::operator+(const Date& d) const{
        //return Gregorian(_numeric + d.getNumeric());
    //}

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
        //return 367*year - 7*(year + (month+9)/12)/4 - 3*((year + (month-9)/7)/100 + 1)/4 + (275*month)/9 + day + 1721029;
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

        set_date(year, month, day);
    }

    bool Gregorian::isLeapYear(int year) const{
        if (year % 400 == 0) return true; 
        if (year % 100 == 0) return false; 
        if (year % 4 == 0) return true; 
        return false;
    }
    
    //std::ostream& operator<<(std::ostream& os, const Gregorian& d){
        //std::streamsize w = os.width();
        //char c = os.fill('0');
        //os << std::setw(4) << d.year()%10000 << 
        //std::setw(1) << "-" << std::setw(2) << d.month() << 
        //std::setw(1) << "-" << std::setw(2) << d.day();
        //os.width(w);
        //os.fill(c);
        //return os; 
    //}
}
