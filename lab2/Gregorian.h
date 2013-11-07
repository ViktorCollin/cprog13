#ifndef GREGORIAN_H
#define GREGORIAN_H
#include "Middle.h"
#include <iomanip>


namespace lab2{

  class Gregorian : public Middle {
    protected: 
      bool isLeapYear(int) const;

      void setCurrentDate();

      void calcYMD() const; 
      unsigned long long YMDtoNumeric(int,int,int) const; 

    public:
      Gregorian();
      Gregorian(int,int,int);
      Gregorian(unsigned long long);
      Gregorian(const Date&);
      
      Gregorian operator++(int);
      Gregorian operator--(int);

  };
  
  //std::ostream & operator<<(std::ostream &, const Gregorian&);

}
#endif

