#include "date.h"
#include <iostream>
#include <iomanip> 

namespace lab2 {

    Date::Date(){
    }
    Date::Date(unsigned long days): _numeric(days) {};
    Date::Date(const Date& d){
        if(this == &d) return;
        _numeric = d.getNumeric();
    }
    unsigned long Date::getNumeric() const {
        return _numeric;
    }
    
    Date& Date::operator=(const Date& d){
        _numeric = d.getNumeric();
        return *this;
    }
    
    Date& Date::operator++(){
        _numeric++;
        return *this;
    }
    
    Date& Date::operator--(){
        _numeric--;
        return *this;
    }
    
    long Date::operator-(const Date& d) const{
        return  _numeric - d.getNumeric();
    }

    Date& Date::operator+=(int n){
        _numeric += n;
        return *this;
    }
    
    Date& Date::operator-=(int n){
        _numeric -= n;
        return *this;
    }

    Date& Date::operator+=(const Date& d){
        _numeric += d.getNumeric();
        return *this;
    }
    
    Date& Date::operator-=(const Date& d){
        _numeric -= d.getNumeric();
        return *this;
    }

    bool Date::operator==(const Date& d) const{
        return _numeric == d.getNumeric();
    }

    bool Date::operator!=(const Date& d) const{
        return _numeric != d.getNumeric();
    }

    bool Date::operator<(const Date& d) const{
        return _numeric < d.getNumeric();
    }

    bool Date::operator<=(const Date& d) const{
        return _numeric <= d.getNumeric();
    }

    bool Date::operator>(const Date& d) const{
        return _numeric > d.getNumeric();
    }

    bool Date::operator>=(const Date& d) const{
        return _numeric >= d.getNumeric();
    }

    std::ostream& operator<<(std::ostream& os, const Date& d){
        char c = os.fill('0');
        os << d.year() << "-" << std::setw(2) << d.month() << "-" << std::setw(2) << d.day();
        os.fill(c);
        return os; 
    }

    long Date::mod_julian_day() const {
        return _numeric - 2400001;
    }
}
