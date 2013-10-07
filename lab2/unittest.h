#ifndef UNIT_TESTER
#define UNIT_TESTER 
#include <cxxtest/TestSuite.h>

#include "Date.h"

class MyTestSuite : public CxxTest::TestSuite {

  public:
    void testContructor() {
      lab2::Date d;
      TS_ASSERT_EQUALS(d.year(), 2013); 
    }
};
#endif
