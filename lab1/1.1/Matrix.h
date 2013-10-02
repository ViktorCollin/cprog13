#ifndef MATRIX_H
#define MATRIX_H
#include "vector.h"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <functional>


//using namespace std;

class Matrix
{
 public:
    typedef unsigned int index;
    
    class matrix_row : private Vector< int >{
    public:
        matrix_row() : Vector< int >( 0 ) {}
        matrix_row( std::size_t s ) : Vector< int >( s ) {}
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
    Matrix operator* ( const Matrix& ) const; //TODO
    Matrix operator* ( int ) const; // TODO
    Matrix operator-( const Matrix& ) const; //TODO
    Matrix operator-( ) const; //TODO
    
    Matrix& transpose( ); //TODO
    
    matrix_row& operator[]( index i );
    const matrix_row& operator[]( index i ) const;
    
    std::size_t rows() const;
    std::size_t cols() const;
    
 protected:
 private:
    Vector< matrix_row >      m_vectors;
    std::size_t                 m_rows;
    std::size_t                 m_cols;
    
    void add_row( matrix_row );            // Non mandatory help function
    friend std::istream& operator>> ( std::istream&, Matrix& );

};

void trim( string& );
std::ostream& operator<< ( std::ostream&, const Matrix&);
template<typename Op>
Matrix& calculate(const Matrix&, const Matrix&, Op);

Matrix::Matrix():m_rows(0), m_cols(0), m_vectors(0, matrix_row(0)) {}

Matrix::Matrix(std::size_t n, std::size_t m):m_rows(n), m_cols(m), m_vectors(n, matrix_row(m)) {}

Matrix::Matrix( const Matrix& m):m_rows(m.rows()), m_cols(m.cols()), m_vectors(m.m_vectors) {}

Matrix::Matrix(int size):m_rows(size), m_cols(size), m_vectors(size, matrix_row(size)) {}

Matrix::~Matrix() { 
	//if(&m_vectors != NULL) delete[] &m_vectors;
}

Matrix& Matrix::operator= ( const Matrix& m ) {
    m_vectors = m.m_vectors;
    m_cols = m.m_cols;
    m_rows = m.m_rows;
    return *this;
}

Matrix Matrix::operator+ ( const Matrix& other) const{
	return calculate(*this, other, std::plus<int>());
	
}
template<typename Op>
Matrix& calculate(const Matrix& m1, const Matrix& m2, Op operand) {
	size_t nr = m1.rows();
	size_t nc = m1.cols();
	if(nr != m2.rows() || nc != m2.cols()) throw std::invalid_argument("Diferent dimentions of matrices");
	Matrix ret(nr, nc);
	for(size_t i=0; i<nr; ++i){
		for(size_t j=0; j<nc; ++j){
			ret[i][j] = operand(m1[i][j],m2[i][j]);
		}
	}
	return ret;
}

Matrix::matrix_row& Matrix::operator[](index i){
	return m_vectors[i];
}

const Matrix::matrix_row& Matrix::operator[]( index i ) const{
	return m_vectors[i];
}

std::size_t Matrix::rows() const {
	return m_rows;
}
std::size_t Matrix::cols() const {
	return m_cols;
}

void Matrix::add_row( matrix_row r) {
    m_vectors.push_back(r);
    ++m_rows; 
}

void trim( string& s){
    
    string::size_type pos = s.find_last_not_of(" []");
    if(pos != string::npos) {
        s.erase(pos + 1);
        pos = s.find_first_not_of(" []");
        if(pos != string::npos) s.erase(0, pos);
    }
    else s.erase(s.begin(), s.end());
}


std::istream& operator>> ( std::istream& is, Matrix& m){
    std::string line;
    std::size_t cols;
    m.m_rows = 0;
    m.m_vectors.clear();
    while(is){
        if (!std::getline(is, line, ';')) break;
        trim(line);
        cols = std::count(line.begin(), line.end(), ' ') + 1;
        Matrix::matrix_row* mrp = new Matrix::matrix_row(cols);    
        std::stringstream s(line);
        Matrix::matrix_row mr = *mrp;
        for(int i = 0; i < cols; ++i){
            s >> mr[i]; 
        }
        m.add_row(mr); 
    }
    m.m_cols = cols;
}
std::ostream& operator<< ( std::ostream& os, const Matrix& m){
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
