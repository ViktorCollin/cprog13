#ifndef UNIT_TESTER
#define UNIT_TESTER 
#include <cxxtest/TestSuite.h>

#include "gregorian.h"
#include "julian.h"
#include "kattistime.h"
using namespace lab2;

class MyTestSuite : public CxxTest::TestSuite {

    public:
        void setUp() {
            time_t tp;
            time(&tp);
            set_k_time(tp);
        }
        
        void testStupid(){
            lab2::Gregorian g(1858, 1, 1);
            TS_ASSERT_EQUALS(g.year(), 1858); 
            TS_ASSERT_EQUALS(g.month(), 1);
            TS_ASSERT_EQUALS(g.day(), 1);
            lab2::Julian j(1858, 1, 1);
            TS_ASSERT_EQUALS(j.year(), 1858); 
            TS_ASSERT_EQUALS(j.month(), 1);
            TS_ASSERT_EQUALS(j.day(), 1);
            lab2::Gregorian g2(2558, 12, 31);
            TS_ASSERT_EQUALS(g2.year(), 2558); 
            TS_ASSERT_EQUALS(g2.month(), 12);
            TS_ASSERT_EQUALS(g2.day(), 31);
            lab2::Julian j2(2558, 12, 31);
            TS_ASSERT_EQUALS(j2.year(), 2558); 
            TS_ASSERT_EQUALS(j2.month(), 12);
            TS_ASSERT_EQUALS(j2.day(), 31);
        }
        
        void testConstructorGreg() {
            lab2::Gregorian d;
            TS_ASSERT_EQUALS(d.year(), 2013); 
            TS_ASSERT_EQUALS(d.month(), 11);
            TS_ASSERT_EQUALS(d.day(), 14);
        }

        void testInvalidConstructorGreg() {
            TS_ASSERT_THROWS(lab2::Gregorian d(2012, 13, 1),std::out_of_range);
        }    
        void testInvalidConstructorGreg1() {
            TS_ASSERT_THROWS(lab2::Gregorian d(2013, 2, 29),std::out_of_range);
        }    
        void testInvalidConstructorGreg2() {
            TS_ASSERT_THROWS_NOTHING(lab2::Gregorian d(2012, 2, 29));
        }    
        void testConstructorJuli() {
            lab2::Julian j;
            TS_ASSERT_EQUALS(j.year(), 2013); 
            TS_ASSERT_EQUALS(j.month(), 11);
            TS_ASSERT_EQUALS(j.day(), 1);
        }
         void testConstructorJuli1111() {
            set_k_time(2005840054);
            lab2::Date * d = new lab2::Julian();
            TS_ASSERT_EQUALS((*d).year(), 2033); 
            TS_ASSERT_EQUALS((*d).month(), 7);
            TS_ASSERT_EQUALS((*d).day(), 11);
        }
       void testDataGivenConstructorJuli() {
            lab2::Julian d(2012, 10, 9);
            TS_ASSERT_EQUALS(d.year(), 2012);
            TS_ASSERT_EQUALS(d.month(), 10);
            TS_ASSERT_EQUALS(d.day(), 9);
        }
        void testDataGivenConstructorJuli1() {
            lab2::Gregorian d(2012, 10, 9);
            lab2::Julian j(d);
            TS_ASSERT_EQUALS(j.year(), 2012);
            TS_ASSERT_EQUALS(j.month(), 9);
            TS_ASSERT_EQUALS(j.day(), 26);
        }

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

        void testAddYear1010(){
            lab2::Gregorian d(2202,3, 25);
            TS_ASSERT_EQUALS(d.month(),3);
            TS_ASSERT_EQUALS(d.year(), 2202);
            TS_ASSERT_EQUALS(d.day(),25);
            d.add_year(1);
            TS_ASSERT_EQUALS(d.month(),3);
            TS_ASSERT_EQUALS(d.year(), 2203);
            TS_ASSERT_EQUALS(d.day(),25);
            d.add_year(1);
            TS_ASSERT_EQUALS(d.month(),3);
            TS_ASSERT_EQUALS(d.year(), 2204);
            TS_ASSERT_EQUALS(d.day(),25);
            d.add_year(1);
            TS_ASSERT_EQUALS(d.month(),3);
            TS_ASSERT_EQUALS(d.year(), 2205);
            TS_ASSERT_EQUALS(d.day(),25);
            d.add_year(1);
            TS_ASSERT_EQUALS(d.month(),3);
            TS_ASSERT_EQUALS(d.year(), 2206);
            TS_ASSERT_EQUALS(d.day(),25);
            d.add_year(1);
            TS_ASSERT_EQUALS(d.month(),3);
            TS_ASSERT_EQUALS(d.year(), 2207);
            TS_ASSERT_EQUALS(d.day(),25);
            d.add_year(1);
            TS_ASSERT_EQUALS(d.month(),3);
            TS_ASSERT_EQUALS(d.year(), 2208);
            TS_ASSERT_EQUALS(d.day(),25);
            d.add_year(1);
            TS_ASSERT_EQUALS(d.month(),3);
            TS_ASSERT_EQUALS(d.year(), 2209);
            TS_ASSERT_EQUALS(d.day(),25);
            d.add_year(1);
            TS_ASSERT_EQUALS(d.month(),3);
            TS_ASSERT_EQUALS(d.year(), 2210);
            TS_ASSERT_EQUALS(d.day(),25);
            d.add_year(1);
            TS_ASSERT_EQUALS(d.month(),3);
            TS_ASSERT_EQUALS(d.year(), 2211);
            TS_ASSERT_EQUALS(d.day(),25);
            d.add_year(1);
            TS_ASSERT_EQUALS(d.month(),3);
            TS_ASSERT_EQUALS(d.year(), 2212);
            TS_ASSERT_EQUALS(d.day(),25);
            d.add_year(1);
            TS_ASSERT_EQUALS(d.month(),3);
            TS_ASSERT_EQUALS(d.year(), 2213);
            TS_ASSERT_EQUALS(d.day(),25);
            d.add_year(1);
            TS_ASSERT_EQUALS(d.month(),3);
            TS_ASSERT_EQUALS(d.year(), 2214);
            TS_ASSERT_EQUALS(d.day(),25);
        }
        void testAddYear11010101010(){
            lab2::Gregorian d(2202,3, 25);
            d.add_year(-13);
            TS_ASSERT_EQUALS(d.month(),3);
            TS_ASSERT_EQUALS(d.year(), 2189);
            TS_ASSERT_EQUALS(d.day(),25);
            d.add_year(13);
            TS_ASSERT_EQUALS(d.month(),3);
            TS_ASSERT_EQUALS(d.year(), 2202);
            TS_ASSERT_EQUALS(d.day(),25);
        } 

        void testAddYearKattis(){
            lab2::Gregorian d(1992,2, 29);
            d.add_year(4);
            TS_ASSERT_EQUALS(d.month(),2);
            TS_ASSERT_EQUALS(d.year(), 1996);
            TS_ASSERT_EQUALS(d.day(),29);
            d.add_year(0);
            TS_ASSERT_EQUALS(d.month(),2);
            TS_ASSERT_EQUALS(d.year(), 1996);
            TS_ASSERT_EQUALS(d.day(),29);
            d.add_year(-5);
            TS_ASSERT_EQUALS(d.month(),2);
            TS_ASSERT_EQUALS(d.year(), 1991);
            TS_ASSERT_EQUALS(d.day(),28);
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
        }
        void testAddYear4() {
            lab2::Gregorian d2(2017,2,28);
            d2.add_year(-1);
            TS_ASSERT_EQUALS(d2.year(), 2016);
            TS_ASSERT_EQUALS(d2.month(),2);
            TS_ASSERT_EQUALS(d2.day(),28);

            d2.add_year(-1);
            TS_ASSERT_EQUALS(d2.year(), 2015);
            TS_ASSERT_EQUALS(d2.month(),2);
            TS_ASSERT_EQUALS(d2.day(),28);
        }

        void testpostfix() {
            lab2::Gregorian d(2013,11,29);
            d++;
            TS_ASSERT_EQUALS(d.day(), 30);
            d++;
            TS_ASSERT_EQUALS(d.day(), 1);
            TS_ASSERT_EQUALS(d.month(), 12);
        }

        void testOutStream() {
            lab2::Gregorian d(2013,11,29);
            std::ostringstream oss;
            oss << d;
            TS_ASSERT_EQUALS(oss.str(), "2013-11-29");

            lab2::Gregorian d2(2013,1,1);
            oss.str("");
            oss.clear();
            oss << d2;
            TS_ASSERT_EQUALS(oss.str(), "2013-01-01");


        }

};
#endif
