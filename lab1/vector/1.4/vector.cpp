#include "vector.h"
#include <iostream>
#include <cstring>
#include <stdexcept>
#include <initializer_list>
using namespace std;

// Vector v
Vector::Vector():_size(0){
	_elements = new unsigned int[0];
}

// Vector(5)
Vector::Vector(size_t size):_size(size){
	_elements = new unsigned int[_size];
	memset(_elements, 0, _size*sizeof(unsigned int));
}

Vector::Vector(const Vector& a):_size(a._size){
	_elements = new unsigned int[_size];
	memcpy(_elements, a._elements, _size*sizeof(unsigned int));
}

Vector::Vector(Vector&& a):_size(a._size){
	_elements = a._elements;
	a._elements = NULL;
	a._size = 0;
}

Vector::Vector(initializer_list<unsigned int> list){
	_size = list.size();
	_elements = new unsigned int[_size];
	size_t i(0);
	for(unsigned int l : list){
		_elements[i++] = l;
	}
}

Vector::~Vector(){
	delete[] _elements;
}

Vector& Vector::operator=(const Vector& a){
	if(this != &a){
		delete[] _elements;
		_size = a._size;
		_elements = new unsigned int[_size];
		memcpy(_elements, a._elements, _size*sizeof(unsigned int));
	}
	return *this;
}

Vector& Vector::operator=(Vector&& a){
	if(this != &a){
		delete[] _elements;
		_size = a._size;
		_elements = a._elements;
		a._elements = NULL;
		a._size = 0;
		
	}
	return *this;
}

Vector& Vector::operator=(initializer_list<unsigned int> list){
	delete[] _elements;
	_size = list.size();
	_elements = new unsigned int[_size];
	size_t i(0);
	for(unsigned int l : list){
		_elements[i++] = l;
	}
	return *this;
}

unsigned int& Vector::operator[](const unsigned int i){
	if(i >= _size || i < 0) throw std::out_of_range ("Index out of Bounce Expection");
	return _elements[i];
}

unsigned int& Vector::operator[](const unsigned int i) const{
	if(i >= _size || i < 0) throw std::out_of_range ("Index out of Bounce Expection");
	return _elements[i];
}

size_t Vector::size() const{
	return _size;
}

/* write to stream */
ostream& operator<<(ostream& os, const Vector &v){
	size_t n = v.size();
	if(!n){
		os << "{}";
		return os;
	}
	--n;
	size_t i;
	os << '{';
	for(i=0; i<n; ++i) os << v[i] << ", ";
	os << v[n] << '}';
	return os;
} 
