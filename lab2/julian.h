#ifndef JULIAN_H
#define JULIAN_H
#include "middle.h"

namespace lab2{

    class Julian : public Middle {
    protected: 
        bool isLeapYear(int) const;

        void setCurrentDate();

        void calcYMD() const; 
        unsigned long long YMDtoNumeric(int,int,int) const;
        
    public:
        Julian();
        Julian(int,int,int);
        Julian(unsigned long long);
        Julian(const Date&);

        Julian operator++(int);
        Julian operator--(int);
    };

}
#endif

