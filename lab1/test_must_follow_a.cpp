#include <cxxtest/TestSuite.h>

#include "must_follow_a.h"

class MyTestSuite : public CxxTest::TestSuite 
{
public:

    // Testcase 1

    // This testcase sets up a 5 sized array (precondition). Note that
    // the second argument (length) to must_follow_a is 4. The
    // expected result is successs.

    // Do make additional tests of your own and try it out. 

    void test_a_is_second_to_last( void )
    {
        char vek[] = {'x', 'x', 'a', 'b', 'x'};
        int result = must_follow_a(vek, 4, 'a', 'b');
        TS_ASSERT_EQUALS( result, 1);
    }
    void test_a_form_peke( void )
    {
        char vek[] = {'b', 'b', 'a', 'b', 'b'};
        int result =  must_follow_a(vek, 3, 'a', 'b');
        TS_ASSERT_EQUALS( result, 0);
    }
    void test_a_vector_is_empty( void )
    {
        char vek[] = {};
        int result = must_follow_a(vek, 0, 'a', 'b');
        TS_ASSERT_EQUALS( result, 0);
    }
    void test_a_form_peke2( void )
    {
        char vek[] = {'b', 'b', 'a' };
        int result =  must_follow_a(vek, 3, 'a', 'b');
        TS_ASSERT_EQUALS( result, 0);
    }
    void test_a_vector_is_one( void )
    {
        char vek[] = {'a'};
        int result = must_follow_a(vek, 0, 'a', 'b');
        TS_ASSERT_EQUALS( result, 0);
    }
    void test_a_vector_is_only_as( void )
    {
        char vek[] = {'a', 'a','a','a'};
        int result = must_follow_a(vek, 4, 'a', 'a');
        TS_ASSERT_EQUALS( result, 3);
    }
 
 
};
