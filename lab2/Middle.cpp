#include "Middle.h"
#include "kattistime.h"
#include <iostream>

namespace lab2 {

    Middle::Middle() : Date() {
        time_t theTime; 
        k_time(&theTime);
        struct tm *aTime = gmtime(&theTime);

        int day = aTime->tm_mday;
        int month = aTime->tm_mon + 1; // Month is 0 - 11, add 1 to get a jan-dec 1-12 concept
        int year = aTime->tm_year + 1900; // Year is # years since 1900

        //Assuming Gregorian system
        int a = (14 - month)/12; 
        int y = year + 4800 - a;
        int m = month + 12*a - 3;

        _numeric = day + (153*m + 2)/5 + 365*y + y/4 - y/100 + y/400 - 32045;
    }

    Middle::Middle(unsigned long long num) : Date(num) {}
    Middle::Middle(const Date& d) : Date(d) {}
}
