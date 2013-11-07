#include <cstdio>
#include <string>
#include "julian.h"
#include <time.h>

namespace lab2{

    Julian::Julian() : Middle(){
    }
    Julian::Julian(int year, int month, int day) : Middle(){
    }

    Julian::Julian(unsigned long long numeric) : Middle(numeric){
    }

    Julian::Julian(const Date& d) : Middle(d){
    }

    Julian Julian::operator++(int i) {
        Julian g(*this);
        _numeric++;
        return g;
    }

    Julian Julian::operator--(int i) {
        Julian g(*this);
        _numeric--;
        return g;
    }

    void Julian::calcYMD() const{
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

    unsigned long long Julian::YMDtoNumeric(int year, int month, int day) const{
        int a = (14 - month)/12; 
        int y = year + 4800 - a;
        int m = month + 12*a - 3;
        return day + (153*m + 2)/5 + 365*y + y/4 - 32083;
    }

    bool Julian::isLeapYear(int year) const{
        if (year % 100 == 0) return false; 
        if (year % 4 == 0) return true;
        return false;
    }
}
