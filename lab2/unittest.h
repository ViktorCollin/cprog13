#ifndef UNIT_TESTER
#define UNIT_TESTER 
#include <cxxtest/TestSuite.h>

#include "Date.h"

class MyTestSuite : public CxxTest::TestSuite {

  public:
    void testConstructor() {
      lab2::Date d;
      TS_ASSERT_EQUALS(d.year(), 2013); 
      TS_ASSERT_EQUALS(d.month(), 10);
    }

    void testDataGivenConstructor() {
      lab2::Date d(2012, 10, 9);
      TS_ASSERT_EQUALS(d.year(), 2012);
      TS_ASSERT_EQUALS(d.month(), 10);
      TS_ASSERT_EQUALS(d.day(), 9);

      //LOW Boundary 
      lab2::Date d2(1800, 01, 02);
      TS_ASSERT_EQUALS(d2.year(), 1800);
      TS_ASSERT_EQUALS(d2.month(), 1);
      TS_ASSERT_EQUALS(d2.day(), 2);


    }

};
#endif
