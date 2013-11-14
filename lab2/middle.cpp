#include "middle.h"
#include "kattistime.h"

namespace lab2 {

    Middle::Middle() : Date() {
        time_t theTime; 
        k_time(&theTime);
        struct tm *aTime = gmtime(&theTime);

        _day = aTime->tm_mday;
        _month = aTime->tm_mon + 1; // Month is 0 - 11, add 1 to get a jan-dec 1-12 concept
        _year = aTime->tm_year + 1900; // Year is # years since 1900

        //Assuming Gregorian system
        int a = (14 - _month)/12; 
        int y = _year + 4800 - a;
        int m = _month + 12*a - 3;

        _numeric = _day + (153*m + 2)/5 + 365*y + y/4 - y/100 + y/400 - 32045;
        calculatedDate = 0;
    }

    Middle::Middle(int year, int month, int day) : Date() {
        calculatedDate = 0;
    }

    Middle::Middle(unsigned long num) : Date(num) {
        calculatedDate = 0;
    }
    Middle::Middle(const Date& d) : Date(d) {
        calculatedDate = 0; 
    }

    const int Middle::_daysOfMonth[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    const std::string Middle::nameOfDay[] = {"","monday", "tuesday",
        "wednesday", "thursday", "friday", "saturday", "sunday"};
    const std::string Middle::nameOfMonth[] = {"","january", "february",
        "march", "april", "may", "june", "july", "august",
        "september", "october", "november", "december"};


    int Middle::year() const {
        if(calculatedDate != _numeric) calcYMD();
        return _year;
    }

    int Middle::month() const {
        if(calculatedDate != _numeric) calcYMD();
        return _month;
    }

    int Middle::day() const {
        if(calculatedDate != _numeric) calcYMD();
        return _day;
    }

    int Middle::week_day() const {
        return _numeric % days_per_week() + 1;
    }

    int Middle::months_per_year() const {
        return 12;
    }

    int Middle::days_per_week() const {
        return 7;
    }

    int Middle::days_month(int y, int m) const{
        while(m > 12) { m -= 12; y++; }
        while(m < 1) { m += 12; y--; }
        if(isLeapYear(y) && m == 2) return 29;
        return _daysOfMonth[m];
    }

    int Middle::days_this_month() const {
        return days_month(year(), month());

    }

    std::string Middle::week_day_name() const {
        return nameOfDay[week_day()];
    }

    std::string Middle::month_name() const {
        return nameOfMonth[month()];
    }

    Middle& Middle::add_year(int n) {
        if(n == 0) return *this;
        int sign = -1;
        if( n > 0)  {
            sign = 1;
        }

        if(isLeapYear()) {
            if(std::abs(n) > 3 && isLeapYear(year() + 4*sign)) {
                _numeric += (365*4 + 1 )*sign;
                n -= sign * 4;
                return add_year(n);
            }else if((sign > 0 && (month() < 3 && !(month() == 2 && day() == 29 ))) ||
                    (sign < 0 && (month() > 2 ||  (month() == 2 && day() == 29 )))) {
                _numeric += 366 * sign;
                n -= sign;
                return add_year(n);
            }
        } else if(isLeapYear(year() + sign) &&
                ((( month() > 2  ||  (month() == 2 && day() == 29 ))&& sign > 0) ||
                    (sign < 0 && (month() < 3  && !(month() == 2 && day() == 29 ))))) {
            _numeric += 366 * sign;
            n -= sign;
            return add_year(n);
        }
        _numeric += 365 * sign;
        n -= sign;
        return add_year(n);
    }

    Middle& Middle::add_month(int n) {
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

    Middle& Middle::add_day(int n) {
        _numeric += n;
        return *this;
    }
    void Middle::set_date(int year, int month, int day) {
        _numeric = YMDtoNumeric(year, month, day);
    }

    bool Middle::isLeapYear() const{
        return isLeapYear(year());
    }
}
