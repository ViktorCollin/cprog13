#include <cstdio>
#include <string>
#include "Date.h"
#include "kattistime.h"
#include <time.h>

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

    //Date& Date::operator++(){
        //_numeric++;
        //return *this;
    //}

    //Date& Date::operator--(){
        //_numeric--;
        //return *this;
    //}
    
    Date& Date::operator+=(const Date& d){
        _numeric += d.getNumeric();
        return *this;
    }
    
    Date& Date::operator-=(const Date& d){
        _numeric -= d.getNumeric();
        return *this;
    }

    inline bool Date::operator==(const Date& d) const{
        return _numeric == d.getNumeric();
    }

    inline bool Date::operator!=(const Date& d) const{
        return _numeric != d.getNumeric();
    }

    inline bool Date::operator<(const Date& d) const{
        return _numeric < d.getNumeric();
    }

    inline bool Date::operator<=(const Date& d) const{
        return _numeric <= d.getNumeric();
    }

    inline bool Date::operator>(const Date& d) const{
        return _numeric > d.getNumeric();
    }

    inline bool Date::operator>=(const Date& d) const{
        return _numeric >= d.getNumeric();
    }

}
