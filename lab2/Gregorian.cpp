#include <cstdio>
#include <string>
#include "Gregorian.h"
#include <time.h>

namespace lab2{

    Gregorian::Gregorian():Middle(){
    }
    Gregorian::Gregorian(int year, int month, int day):Middle(year,month,day){

    }
    Gregorian::Gregorian(unsigned long long numeric):Middle(numeric){

    }
    Gregorian::Gregorian(const Date& d):Middle(d){

    }
    int Gregorian::year() const {
        if(calculatedDate != _days) calcYMD();
        return _year;
    }

    int Gregorian::month() const {
        if(calculatedDate != _days) calcYMD();
        return _month;
    }

    int Gregorian::day() const {
        if(calculatedDate != _days) calcYMD();
        return _day;
    }

    inline int Gregorian::week_day() const {
        return _days % days_per_week() + 1;
    }
    
    int Gregorian::months_per_year() const {
        return 12;
    }

    inline int Gregorian::days_per_week() const {
        return 7;
    }
    
    int days_month(int y, int m){
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
        return *this;
    }
    
    Gregorian& Gregorian::add_month(int n) {
       int fac = -1;
       if( n > 0) fac = 1;
       _month += n;
       while(_month >= 13 || _month <= 0) {
           _month -= fac*12;
           _year += fac;
       }
       verifyDay();
       return *this;
    }

    Gregorian& Gregorian::add_day(int n) {
        
        return *this;
    }

    void Gregorian::verifyDay() {
        //TODO kolla skottår för februari
        if(_day > _daysOfMonth[_month - 1]) _day = _daysOfMonth[_month -1];
    }

    mutable void calcYMD(){

    }
    
    unsigned long long YMDtoNumeric(int y, int m, int d){
        
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
        _days = YMDtoNumeric(year, mont, day);
        _year = year;
        _month = month;
        _day = day;
        calculatedDate = _days;
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
