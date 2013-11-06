#ifndef UNIT_TESTER
#define UNIT_TESTER 
#include <cxxtest/TestSuite.h>

#include "Gregorian.h"
#include "Julian.h"
#include "kattistime.h"
using namespace lab2;

class MyTestSuite : public CxxTest::TestSuite {

    public:
        void setUp() {
            time_t tp;
            time(&tp);
            set_k_time(tp);
        }

        void testConstructorGreg() {
            lab2::Gregorian d;
            TS_ASSERT_EQUALS(d.year(), 2013); 
            TS_ASSERT_EQUALS(d.month(), 11);
        }
        //void testConstructorJuli() {
        //lab2::Julian j;
        //TS_ASSERT_EQUALS(j.year(), 2013); 
        //TS_ASSERT_EQUALS(j.month(), 11);
        //}

        void testDataGivenConstructor() {
            lab2::Gregorian d(2012, 10, 9);
            TS_ASSERT_EQUALS(d.year(), 2012);
            TS_ASSERT_EQUALS(d.month(), 10);
            TS_ASSERT_EQUALS(d.day(), 9);

            //LOW Boundary 
            lab2::Gregorian d2(1800, 01, 02);
            TS_ASSERT_EQUALS(d2.year(), 1800);
            TS_ASSERT_EQUALS(d2.month(), 1);
            TS_ASSERT_EQUALS(d2.day(), 2);

            //HIGH Boundary 
            lab2::Gregorian d3(2558, 12, 31);
            TS_ASSERT_EQUALS(d3.year(), 2558);
            TS_ASSERT_EQUALS(d3.month(), 12);
            TS_ASSERT_EQUALS(d3.day(), 31);
        }

        void testAddMonth(){
            lab2::Gregorian d(2012,10, 31);
            d.add_month();
            TS_ASSERT_EQUALS(d.month(),11);
            TS_ASSERT_EQUALS(d.year(), 2012);
            TS_ASSERT_EQUALS(d.day(),30);
        }

        void testAddMonth2() {
            lab2::Gregorian d(2012,11, 30);
            d.add_month(-2);
            TS_ASSERT_EQUALS(d.month(),9);
            TS_ASSERT_EQUALS(d.day(),30);
        }

        void testAddMonth3() {
            lab2::Gregorian d(2012, 9, 30);
            d.add_month(10);
            TS_ASSERT_EQUALS(d.month(),8);
            TS_ASSERT_EQUALS(d.day(),1);
            TS_ASSERT_EQUALS(d.year(), 2013);
        }

        void testAddMonth31() {
            lab2::Gregorian d(2012, 12, 30);
            d.add_month(1);
            TS_ASSERT_EQUALS(d.month(),1);
            TS_ASSERT_EQUALS(d.day(),30);
            TS_ASSERT_EQUALS(d.year(), 2013);
        }

        void testAddMonth32() {
            lab2::Gregorian d2(2012,1, 1);
            d2.add_month(12);
            TS_ASSERT_EQUALS(d2.month(),1);
            TS_ASSERT_EQUALS(d2.day(),1);
            TS_ASSERT_EQUALS(d2.year(), 2013);
        }

        void testAddMonth4() {
            lab2::Gregorian d(2012, 3, 1);
            d.add_month(-1);
            TS_ASSERT_EQUALS(d.month(),2);
            TS_ASSERT_EQUALS(d.day(),1);
            TS_ASSERT_EQUALS(d.year(), 2012);
        }

        void testAddMonth41() {
            lab2::Gregorian d(2013, 8, 1);
            d.add_month(-9);
            TS_ASSERT_EQUALS(d.month(),11);
            TS_ASSERT_EQUALS(d.day(),1);
            TS_ASSERT_EQUALS(d.year(), 2012);
        }

        void testAddMonth5() {
            lab2::Gregorian d2(2012,1, 31);
            d2.add_month();
            TS_ASSERT_EQUALS(d2.month(),3);
            TS_ASSERT_EQUALS(d2.day(),1);
        }

        void testAddYear(){
            lab2::Gregorian dd(2011,1,1);
            dd.add_year();
            TS_ASSERT_EQUALS(dd.year(), 2012);
            TS_ASSERT_EQUALS(dd.month(),1);
            TS_ASSERT_EQUALS(dd.day(),1);
        }

        void testAddYear1() {
            lab2::Gregorian d(2012,1,1);
            d.add_year();
            TS_ASSERT_EQUALS(d.year(), 2013);
            TS_ASSERT_EQUALS(d.month(),1);
            TS_ASSERT_EQUALS(d.day(),1);
        }

        void testAddYear2() {
            lab2::Gregorian d2(2012,2,29);
            d2.add_year(4);
            TS_ASSERT_EQUALS(d2.year(), 2016);
            TS_ASSERT_EQUALS(d2.month(),2);
            TS_ASSERT_EQUALS(d2.day(),29);
        }

        void testAddYear3() {
            lab2::Gregorian d2(2016,2,29);
            d2.add_year();
            TS_ASSERT_EQUALS(d2.year(), 2017);
            TS_ASSERT_EQUALS(d2.month(),2);
            TS_ASSERT_EQUALS(d2.day(),28);

            d2.add_year(-1);
            TS_ASSERT_EQUALS(d2.year(), 2016);
            TS_ASSERT_EQUALS(d2.month(),2);
            TS_ASSERT_EQUALS(d2.day(),28);

            d2.add_year(-1);
            TS_ASSERT_EQUALS(d2.year(), 2015);
            TS_ASSERT_EQUALS(d2.month(),2);
            TS_ASSERT_EQUALS(d2.day(),28);
        }

        //void testprefix() {
            //lab2::Gregorian d(2013,11,29);
            //++d;
            //TS_ASSERT_EQUALS(d.day(), 30);
            //++d;
            //TS_ASSERT_EQUALS(d.day(), 1);
            //TS_ASSERT_EQUALS(d.month(), 12);
        //}

        void testpostfix() {
            lab2::Gregorian d(2013,11,29);
            d++;
            TS_ASSERT_EQUALS(d.day(), 30);
            d++;
            TS_ASSERT_EQUALS(d.day(), 1);
            TS_ASSERT_EQUALS(d.month(), 12);
        }

};
#endif
