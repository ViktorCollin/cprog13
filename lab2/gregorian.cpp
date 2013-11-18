#include "gregorian.h"
#include <stdexcept>

namespace lab2{

    Gregorian::Gregorian():Middle(){
    }

    Gregorian::Gregorian(int year, int month, int day):Middle(year,month,day){
        set_date(year,month,day);
    }

    Gregorian::Gregorian(unsigned long numeric):Middle(numeric){
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

    void Gregorian::calcYMD() const{
        if(calculatedDate == _numeric) return;
        int y = 4716, j = 1401, m = 2, n = 12, r = 4, p = 1461, v = 3, u = 5,
            s = 153, w = 2, B = 274277, C = -38;
        unsigned long f = _numeric + j + (((4 * _numeric + B)/146097)*3)/4+C;
        unsigned long e = r * f + v;
        unsigned int g = (e % p) /r;
        unsigned int h = u * g + w;
        _day = (h % s)/u + 1;
        _month = ((h/s + m) % n) + 1;
        _year = e/p - y + (n+m - _month)/n;
        calculatedDate = _numeric;
    }

    unsigned long Gregorian::YMDtoNumeric(int year, int month, int day) const{
        if(month < 1 || month > 12 || day < 1 || day > days_month(year, month))
            throw std::out_of_range("The date imported is not valid");
        int a = (14 - month)/12; 
        int y = year + 4800 - a;
        int m = month + 12*a - 3;
        return day + (153*m + 2)/5 + 365*y + y/4 - y/100 + y/400 - 32045;
    }

    bool Gregorian::isLeapYear(int year) const{
        if (year % 400 == 0) return true; 
        if (year % 100 == 0) return false; 
        if (!(year & 3)) return true; // year % 4 == 0 
        return false;
    }
}
