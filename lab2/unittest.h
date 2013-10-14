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
      
      //HIGH Boundary 
      lab2::Date d3(2558, 12, 31);
      TS_ASSERT_EQUALS(d3.year(), 2558);
      TS_ASSERT_EQUALS(d3.month(), 12);
      TS_ASSERT_EQUALS(d3.day(), 31);

    }

    void testAddMonth(){
      lab2::Date d(2012,10, 31);
      d.add_month();
      TS_ASSERT_EQUALS(d.month(),11);
      TS_ASSERT_EQUALS(d.day(),30);
      d.add_month(-2);
      TS_ASSERT_EQUALS(d.month(),9);
      d.add_month(10);
      TS_ASSERT_EQUALS(d.month(),7);
      TS_ASSERT_EQUALS(d.year(), 2013);
      d.add_month(-9);
      TS_ASSERT_EQUALS(d.month(),10);
      TS_ASSERT_EQUALS(d.year(), 2012);
    }

    //void testDaysThisMonth() {
      //lab2::Date d(2012,10, 31);
      
      //lab2::Date d(2012,10, 31);

};
#endif
