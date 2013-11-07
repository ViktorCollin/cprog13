#include <cstdio>
#include <string>
#include "Date.h"
#include "kattistime.h"
#include <time.h>
#include <stdexcept>
#include <iomanip> 

namespace lab2 {

    Date::Date(){
    }
    Date::Date(unsigned long long days): _numeric(days) {};
    Date::Date(const Date& d){
        if(this == &d) return;
        _numeric = d.getNumeric();
    }
    unsigned long long Date::getNumeric() const {
        return _numeric;
    }

    Date& Date::operator=(Date&& d){
        _numeric = std::move(d.getNumeric());
        return *this;
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

    //std::ostream& operator<<(std::ostream& os, const Date& d){
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
