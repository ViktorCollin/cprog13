#ifndef MATRIX_H
#define MATRIX_H
#include <vector>
#include <iostream>
#include <stdexcept>

template <class T>
class Vector : public std::vector< T > {
public:
    explicit Vector <T> (std::size_t size  = 0, T data = T()) : std::vector<T>(size, data) {}
    const T& operator[](unsigned int i) const throw(std::out_of_range) {
        return this->at( i );
    }
    T& operator[](unsigned int i) throw(std::out_of_range) {
        return this->at( i );
    }    
};

//using namespace std;

class Matrix
{
 public:
    typedef unsigned int index;
    
    class matrix_row : private Vector< int >{
    public:
        matrix_row( std::size_t s = 0) : Vector< int >( s ) {}
        using Vector<int>::operator [];
    private:
        friend std::istream& operator>>( std::istream&, Matrix& );
    };
    
    Matrix( );
    Matrix( std::size_t, std::size_t );
    Matrix( const Matrix& );
    Matrix(int size);
    ~Matrix( );
    
    Matrix& operator= ( const Matrix& );
    Matrix operator+ ( const Matrix& ) const;
    Matrix operator* ( const Matrix& ) const;
    Matrix operator* ( int ) const;
    Matrix operator-( const Matrix& ) const;
    Matrix operator-( ) const;
    
    Matrix& transpose( );
    
    matrix_row& operator[]( index i );
    const matrix_row& operator[]( index i ) const;
    
    std::size_t rows() const;
    std::size_t cols() const;
    
 protected:
 private:
    Vector< matrix_row >        m_vectors;
    std::size_t                 m_rows;
    std::size_t                 m_cols;
    
    void add_row( );            // Non mandatory help function
    friend std::istream& operator>> ( std::istream&, Matrix& );
};

std::istream& operator>> ( std::istream&, Matrix& );
std::ostream& operator<< ( std::ostream& os, Matrix& m){
	os << "[ ";
	std::size_t n = m.rows()-1;
	std::size_t cols = m.cols();
	for(std::size_t i=0; i<n; ++i){
		for(std::size_t j=0; j<cols; ++j){
			os << m[i][j] << ' ';
		}
		os << "\n; ";
	}
	for(std::size_t j=0; j<cols; ++j){
		os << m[n][j] << ' ';
	}
	os << ']';
	return os;
}
Matrix operator* ( int, const Matrix& );

#endif // MATRIX_H
