#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cstring>
#include <stdexcept>
#include <initializer_list>
#include <algorithm>

using namespace std;
static const size_t DEFAULT_INIT_SIZE(16);
static const size_t SHRINK_VECTOR_FRACTION(4);
static const size_t SHRINK_VECTOR_AMOUNT(2);


template <typename T>
class Vector{
	private:
		T* _elements;
		size_t _size;
		size_t _maxSize;

	public:
		Vector();
		explicit Vector(size_t);
		Vector(size_t, T);
		Vector(const Vector<T>&);
		Vector(Vector<T>&&);
		Vector(initializer_list<T>);
		~Vector();
		
		Vector<T>& operator=(const Vector<T>&);
		Vector<T>& operator=(Vector<T>&&);
		Vector<T>& operator=(initializer_list<T>);
		
		T& operator[](const size_t);
		T& operator[](const size_t) const;
		
		size_t size() const;
		size_t maxSize() const;
		void clear();
		bool exists(const T&) const;
		void sort(bool = true);
		void push_back(T);
		T* insert(size_t, T);
		T* erase(size_t);
		
};

template <typename T>
Vector<T>::Vector():_size(0), _maxSize(DEFAULT_INIT_SIZE){
	_elements = new T[DEFAULT_INIT_SIZE];
}

template <typename T>
Vector<T>::Vector(size_t size){
	Vector(size, T());
}

template <typename T>
Vector<T>::Vector(size_t size, T e):_size(size), _maxSize(max(_size, DEFAULT_INIT_SIZE)){
	_elements = new T[_maxSize];
	for(size_t i=0; i<_size; ++i) _elements[i] = e;
}

template <typename T>
Vector<T>::Vector(const Vector<T>& a):_size(a._size), _maxSize(a._maxSize){
	_elements = new T[_maxSize];
	for(size_t i=0; i<_size; ++i) _elements[i] = a[i];
}

template <typename T>
Vector<T>::Vector(Vector<T>&& a):_size(a._size), _maxSize(a._maxSize){
	_elements = a._elements;
	a._elements = NULL;
	a._size = 0;
	a._maxSize = 0;
}

template <typename T>
Vector<T>::Vector(initializer_list<T> list){
	_size = list.size();
	_maxSize = max(DEFAULT_INIT_SIZE,_size);
	_elements = new T[_maxSize];
	size_t i(0);
	for(T l : list) _elements[i++] = l;
}

template <typename T>
Vector<T>::~Vector(){
	if(_elements != NULL) delete[] _elements;
}

// Asinment operators
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& a){
	if(this != &a){
		delete[] _elements;
		_size = a._size;
		_maxSize = a._maxSize;
		_elements = new T[_maxSize];
		for(size_t i=0; i<_size; ++i) _elements[i] = a[i];
	}
	return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& a){
	if(this != &a){
		delete[] _elements;
		_size = a._size;
		_maxSize = a._maxSize;
		_elements = a._elements;
		a._elements = NULL;
		a._size = 0;
		a._maxSize = 0;

	}
	return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator=(initializer_list<T> list){
	delete[] _elements;
	_size = list.size();
	_maxSize = max(DEFAULT_INIT_SIZE, _size);
	_elements = new T[_maxSize];
	size_t i(0);
	for(T l : list) _elements[i++] = l;
	return *this;
}

template <typename T>
T& Vector<T>::operator[](const size_t i){
	if(i >= _size || i < 0) throw std::out_of_range ("Index out of Bounce Expection");
	return _elements[i];
}

template <typename T>
T& Vector<T>::operator[](const size_t i) const{
	if(i >= _size || i < 0) throw std::out_of_range ("Index out of Bounce Expection");
	return _elements[i];
}

// Functions
template <typename T>
size_t Vector<T>::size() const{
	return _size;
}

template <typename T>
size_t Vector<T>::maxSize() const{
	return _maxSize;
}

template <typename T>
void Vector<T>::clear(){
	delete[] _elements;
	_elements = new T[DEFAULT_INIT_SIZE];
	_size = 0;
	_maxSize = DEFAULT_INIT_SIZE;
}

template <typename T>
bool Vector<T>::exists(const T& v) const{
	return *std::find(_elements, _elements+_size, v) == v;
}

template <typename S>
struct Comparator : public std::binary_function<S,S,bool>{
	bool operator()(const S& o1, const S& o2){
		return o2 < o1;
	}
};

template <typename T>
void Vector<T>::sort(bool ascending /*default true*/){
	if(ascending){
		std::sort(_elements, _elements+_size);
	}else{
		std::sort(_elements, _elements+_size, Comparator<T>());
	}	
}

template <typename T>
void Vector<T>::push_back(T v){
	(void)insert(_size, v);
}

template <typename T>
T* Vector<T>::insert(size_t i, T v){
	if(i > _size || i < 0) throw std::out_of_range ("Index out of Bounce Expection");
	if(_size == _maxSize){
		if(_maxSize) _maxSize = 2*_maxSize;
		else _maxSize = DEFAULT_INIT_SIZE;
		T * newArray = new T[_maxSize];
		size_t j(0);
		while(j<i) newArray[j] = _elements[j++];
		while(j<_size) newArray[++j] = _elements[j-1];
		delete[] _elements;
		_elements = newArray;
	}else{
		for(size_t j=_size; i<j;) _elements[j] = _elements[--j];
	}
	_elements[i] = v;
	++_size;
	return _elements+i;
}

template <typename T>
T* Vector<T>::erase(size_t i){
	if(i >= _size || i < 0) throw std::out_of_range ("Index out of Bounce Expection");
	for(size_t j=i; j<_size; ) _elements[j] = _elements[++j];
	--_size;
	if(_size*SHRINK_VECTOR_FRACTION <= _maxSize) {
		_maxSize = max(DEFAULT_INIT_SIZE, _maxSize/SHRINK_VECTOR_AMOUNT);
		T* newArray = new T[_maxSize];
		for(size_t k=0; k<_size; k++) newArray[k] = _elements[k];
		delete[] _elements;
		_elements = newArray;
	}
	return _elements+i;
}


/* write to stream */
template <typename T>
ostream& operator<<(ostream& os, const Vector<T>& v){
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


#endif
