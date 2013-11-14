#include "julian.h"
#include <stdexcept>

namespace lab2{

    Julian::Julian() : Middle(){
    }
    Julian::Julian(int year, int month, int day) : Middle(year,month,day){
        set_date(year,month,day);
    }

    Julian::Julian(unsigned long numeric) : Middle(numeric){
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
        if(calculatedDate == _numeric) return;
        int b = _numeric + 1524;
        int c = (int)((b - 122.1) / 365.25);
        int da = (int)(365.25 * c);
        int e = (int)((b - da) / 30.6001);
        _month = (int)( (e < 14) ? (e - 1) : (e - 13) );
        _year = (int)( (_month > 2 ) ? (c - 4716) : (c - 4715));
        _day = (int)(b-da-(int)(30.6001*e));
        calculatedDate = _numeric;
    }

    unsigned long Julian::YMDtoNumeric(int year, int month, int day) const{
        if(month < 1 || month > 12 || day < 1 || day > days_month(year, month))
            throw std::out_of_range("The date imported is not valid");
        int a = (14 - month)/12; 
        int y = year + 4800 - a;
        int m = month + 12*a - 3;
        //std::cerr << "J: Num: " << (day + (153*m + 2)/5 + 365*y + y/4 - 32083) << " year: "<< year << " month: "<< month <<" day: " << day << std::endl ;
        return day + (153*m + 2)/5 + 365*y + y/4 - 32083;
    }

    bool Julian::isLeapYear(int year) const{
        if (!(year & 3)) return true; // year % 4 == 0 
        return false;
    }
}
