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
        _numeric = d.getDays();
    }
    unsigned long long Date::getDays() const {
        return _numeric;
    }
}
