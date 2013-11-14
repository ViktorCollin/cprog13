#ifndef CAL_TESTER
#define CAL_TESTER 
#include <cxxtest/TestSuite.h>
#include <iostream>
#include "gregorian.h"
#include "julian.h"
#include "calendar.h"
#include "kattistime.h"
using namespace lab2;

class CalTestSuite : public CxxTest::TestSuite {

    public:
        void setUp() {
            time_t tp;
            time(&tp);
            set_k_time(tp);
        }
        void testConstructorCal1() {
            lab2::Calendar<Gregorian> cal;
            std::ostringstream oss;
            oss << cal.getToday();
            TS_ASSERT_EQUALS(oss.str(), "2013-11-14");
        }

        void testConstructorCal() {
            lab2::Calendar<Gregorian> cal;
            TS_ASSERT_EQUALS(cal.getToday().year(), 2013); 
            TS_ASSERT_EQUALS(cal.getToday().month(), 11);
            TS_ASSERT_EQUALS(cal.getToday().day(), 14);
        }

        void testIntConstructorCal() {
            lab2::Calendar<Gregorian> cal;
            cal.set_date(2013, 12, 24);
            TS_ASSERT_EQUALS(cal.getToday().year(), 2013); 
            TS_ASSERT_EQUALS(cal.getToday().month(), 12);
            TS_ASSERT_EQUALS(cal.getToday().day(), 24);
        } 

        void testAddEvent(){
            lab2::Calendar<Gregorian> cal;
            TS_ASSERT_EQUALS(cal.getEventList().size(), 0);
            cal.add_event("Julafton", 24, 12, 2013);
            TS_ASSERT_EQUALS(cal.getEventList().size(), 1);

        }   

        void testRemoveEvent(){
            lab2::Calendar<Gregorian> cal;
            TS_ASSERT_EQUALS(cal.getEventList().size(), 0);
            cal.add_event("Julafton", 24, 12, 2013);
            TS_ASSERT_EQUALS(cal.getEventList().size(), 1);
            cal.remove_event("Julafton", 24, 12, 2013);           
            TS_ASSERT_EQUALS(cal.getEventList().size(), 1);
            std::map<Gregorian, std::vector<std::string> > g = cal.getEventList();

            TS_ASSERT_EQUALS(g[Gregorian(2013,12,24)].size(), 0);
        }   

        void testAddEasdsfvent(){
            lab2::Calendar<Gregorian> cal;
            cal.add_event("Julafton", 24, 12, 2013);
            TS_ASSERT_EQUALS(cal.getEventList().size(), 1);
            std::ostringstream oss;
            oss << cal;
            TS_ASSERT_EQUALS(oss.str(), "2013-12-24 : Julafton\n");
            cal.add_event("Test denna ska inte synas", 24, 12, 2000);
            TS_ASSERT_EQUALS(oss.str(), "2013-12-24 : Julafton\n");
        }   

        void testingtesting() {
            set_k_time(1600442475);
            lab2::Calendar<Gregorian> cal;
            cal.add_event("Julafton", 29, 2, 2012);
            cal.set_date(2100, 2, 6);
            cal.remove_event("something", 29);
        }

        void testingtestingtesting1() {
            lab2::Calendar<Gregorian> cal;
            TS_ASSERT_EQUALS(cal.remove_event("something", 2), false);
        }
        void testingtestingtesting2() {
            lab2::Calendar<Gregorian> cal;
            TS_ASSERT_EQUALS(cal.remove_event("something", 2), false);
            TS_ASSERT_EQUALS(cal.add_event("Julafton", 2, 2, 2012), true);
        }
        void testingtestingtesting3() {
            lab2::Calendar<Gregorian> cal;
            TS_ASSERT_EQUALS(cal.remove_event("something", 2), false);
            TS_ASSERT_EQUALS(cal.add_event("Julafton", 2, 2, 2012), true);
            TS_ASSERT_EQUALS(cal.remove_event("something", 2, 2, 2012), false);
        }
        void testingtestingtesting4() {
            lab2::Calendar<Gregorian> cal;
            TS_ASSERT_EQUALS(cal.remove_event("something", 2), false);
            TS_ASSERT_EQUALS(cal.add_event("Julafton", 2, 2, 2012), true);
            TS_ASSERT_EQUALS(cal.remove_event("something", 2, 2, 2012), false);
            cal.set_date(2012,2,1);
            TS_ASSERT_EQUALS(cal.remove_event("Julafton", 2, 2, 2012), true);
        }
        void testingtestingtesting5() {
            lab2::Calendar<Gregorian> cal;
            TS_ASSERT_EQUALS(cal.remove_event("something", 2), false);
            TS_ASSERT_EQUALS(cal.add_event("Julafton", 2, 2, 2012), true);
            TS_ASSERT_EQUALS(cal.remove_event("something", 2, 2, 2012), false);
            TS_ASSERT_EQUALS(cal.remove_event("Julafton", 2, 2, 2012), true);
            TS_ASSERT_EQUALS(cal.remove_event("something", 2, 2, 2012), false);
        }
        void testingtestingtesting6() {
            lab2::Calendar<Gregorian> cal;
            TS_ASSERT_EQUALS(cal.remove_event("something", 2), false);
            TS_ASSERT_EQUALS(cal.add_event("Julafton", 2, 2, 2012), true);
            TS_ASSERT_EQUALS(cal.remove_event("something", 2, 2, 2012), false);
            TS_ASSERT_EQUALS(cal.remove_event("Julafton", 2, 2, 2012), true);
            TS_ASSERT_EQUALS(cal.remove_event("something", 2, 2, 2012), false);
            TS_ASSERT_EQUALS(cal.remove_event("Julafton", 2, 2, 2012), false);
        }
        void testarlite() {
            lab2::Calendar<Julian> cal;

            TS_ASSERT_EQUALS(cal.set_date(2100,8,26), true);
            TS_ASSERT_EQUALS(cal.add_event("Julafto123456n", 16,8), true);
            TS_ASSERT_EQUALS(cal.add_event("Julafto1alsjfhas23456n", 16,8,2100), true);

            TS_ASSERT_EQUALS(cal.add_event("Julafton", 16), true);
        }
};
#endif
