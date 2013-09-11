#include "vector.h"
#include <cstring>
#include <stdexcept>
using namespace std;

Vector::Vector():_size(0){
	_elements = new unsigned int[0];
}

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
	if(i >= _size) throw std::out_of_range ("");
	return _elements[i];
}

unsigned int& Vector::operator[](const unsigned int i) const{
	if(i >= _size) throw std::out_of_range ("");
	return _elements[i];
}