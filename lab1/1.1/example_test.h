#ifndef MATRIX_TEST_H_INCLUDED
#define MATRIX_TEST_H_INCLUDED

#include "Matrix.h"
#include "../cxxtest/cxxtest/TestSuite.h"
#include <fstream>
#include <sstream>

class MatrixTestSuite : public CxxTest::TestSuite
{

    Matrix a_matrix_3by2() {    // [ 1 3 5 ]
        Matrix m;               // [ 0 2 0 ]
        std::stringstream s("  [ 1 3 5 ; 0 2 0 ]");
        s >> m;
        return m;
    }

    void init_matrix( Matrix& m, const char* file )
    {
        std::stringstream stream( file );   
        stream >> m;
    }

public:
    void testIndexOperator ( )
    {
        Matrix m( 2, 2 );
        TS_ASSERT( m[ 0 ][ 1 ] == 0 );
    
    }
    void testStringStreamConstructor ( ) 
    {
        Matrix m = a_matrix_3by2();
        TS_ASSERT( m[ 0 ][ 0 ] == 1);
    }
    void testIndex2Operator ( )
    {
        Matrix m( 2, 2);
        init_matrix(m, "  [ 1 3 5 ; 0 2 1 ]");
        TS_ASSERT( m[ 0 ][ 0 ] == 1 );
        TS_ASSERT( m[ 1 ][ 2 ] == 1 );

        std::stringstream ss;
        ss << m;
        ss >> m;
        TS_ASSERT( m[ 0 ][ 0 ] == 1 );
    }
    void testRowSize ( ){
        Matrix m; 
        TS_ASSERT_EQUALS(m.rows() , 0);
        m = a_matrix_3by2();
        TS_ASSERT_EQUALS(m.rows() , 2);
    }
    void testColSize ( ){
        Matrix m;
        TS_ASSERT_EQUALS(m.cols() , 0);
        m = a_matrix_3by2();
        TS_ASSERT_EQUALS(m.cols() , 3);
    }

	void testPlusSame(){
		Matrix m3, m1 = a_matrix_3by2(), m2 = a_matrix_3by2();
		m3 = m1 + m2;
		TS_ASSERT_EQUALS(m1.rows(), m3.rows());
		TS_ASSERT_EQUALS(m1.cols(), m3.cols());
		TS_ASSERT_EQUALS(m3[0][0], 2);
		TS_ASSERT_EQUALS(m3[0][1], 6);
		TS_ASSERT_EQUALS(m3[0][2], 10);
		TS_ASSERT_EQUALS(m3[1][0], 0);
		TS_ASSERT_EQUALS(m3[1][1], 4);
		TS_ASSERT_EQUALS(m3[1][2], 0);
		
	}
};

#endif

