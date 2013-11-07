#ifndef GREGORIAN_H
#define GREGORIAN_H
#include "Middle.h"


namespace lab2{

    class Gregorian : public Middle {
    protected: 


        void setCurrentDate();

        void calcYMD() const; 
        unsigned long long YMDtoNumeric(int,int,int) const; 

    public:
        bool isLeapYear(int) const;
        Gregorian();
        Gregorian(int,int,int);
        Gregorian(unsigned long long);
        Gregorian(const Date&);

        Gregorian operator++(int);
        Gregorian operator--(int);

    };

}
#endif

