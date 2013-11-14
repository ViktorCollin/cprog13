#ifndef GREGORIAN_H
#define GREGORIAN_H
#include "middle.h"


namespace lab2{

    class Gregorian : public Middle {
    protected: 

        bool isLeapYear(int) const;
        void setCurrentDate();

        void calcYMD() const; 
        unsigned long YMDtoNumeric(int,int,int) const; 

    public:
        Gregorian();
        Gregorian(int,int,int);
        Gregorian(unsigned long);
        Gregorian(const Date&);

        //Gregorian operator-(const Date&) const;
        //Gregorian operator+(const Date&) const;

        Gregorian operator++(int);
        Gregorian operator--(int);

    };
}
#endif

