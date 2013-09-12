#ifndef VECTOR_H
#define VECTOR_H
#define DEFAULT_INIT_SIZE 16

#include <iostream>
#include <cstring>
#include <stdexcept>
#include <initializer_list>
#include <algorithm>


using namespace std;
template <class T>
class Vector{
private:
	T* _elements;
	size_t _size;
	size_t _maxSize;
	
	bool decending(T i, T j){
		return j < i;
	}

public:
	
	// Constructors
	Vector():_size(0), _maxSize(DEFAULT_INIT_SIZE){
		_elements = new T[DEFAULT_INIT_SIZE];
	}

	explicit Vector(size_t size):_size(size), _maxSize(_size){
		_elements = new T[_size];
		for(size_t i=0; i<_size; ++i) _elements[i] = T();
	}

	Vector(const Vector<T>& a):_size(a._size), _maxSize(_size){
		_elements = new T[_size];
		for(size_t i=0; i<_size; ++i) _elements[i] = a[i];
	}

	Vector(Vector<T>&& a):_size(a._size), _maxSize(_size){
		_elements = a._elements;
		a._elements = NULL;
		a._size = 0;
		a._maxSize = 0;
	}

	Vector(initializer_list<T> list){
		_size = list.size();
		_maxSize = _size;
		_elements = new T[_size];
		size_t i(0);
		for(T l : list) _elements[i++] = l;
	}
	
	~Vector(){
		delete[] _elements;
	}
	
	// Asinment operators
	Vector<T>& operator=(const Vector<T>& a){
		if(this != &a){
			delete[] _elements;
			_size = a._size;
			_maxSize = a._maxSize;
			_elements = new T[_size];
			for(size_t i=0; i<_size; ++i) _elements[i] = a[i];
		}
		return *this;
	}

	Vector<T>& operator=(Vector<T>&& a){
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

	Vector<T>& operator=(initializer_list<T> list){
		delete[] _elements;
		_size = list.size();
		_maxSize = _size;
		_elements = new T[_size];
		size_t i(0);
		for(T l : list) _elements[i++] = l;
		return *this;
	}

	T& operator[](const size_t i){
		if(i >= _size || i < 0) throw std::out_of_range ("Index out of Bounce Expection");
		return _elements[i];
	}

	T& operator[](const size_t i) const{
		if(i >= _size || i < 0) throw std::out_of_range ("Index out of Bounce Expection");
		return _elements[i];
	}

	// Functions
	size_t size() const{
		return _size;
	}
	
	size_t maxSize() const{
		return _maxSize;
	}
	
	void clear(){
		delete[] _elements;
		_size = 0;
		_maxSize = 0;
	}
	
	bool exists(const T& v){
		return find(_elements, _elements+_size, v) == v;
	}
	
	void sort(bool ascending = true){
		if(ascending){
			sort(_elements, _elements+_size);
		}else{
			sort(_elements, _elements+_size, decending);
		}	
	}
	
	void push_back(T v){
		insert(_size, v);
	}
	
	T* insert(size_t i, T v){
		if(i > _size || i < 0) throw std::out_of_range ("Index out of Bounce Expection");
		if(_size == _maxSize){
			_maxSize = 2*_maxSize;
			T * newArray = new T[_maxSize];
			for(size_t j=0; j<i; ++j) newArray[j] = _elements[j];
			delete[] _elements;
			_elements = newArray;
		}else{
			for(size_t j=_size; j>i;) _elements[j] = _elements[--j];
		}
		_elements[i] = v;
		++_size;
	}
	
	T* erase(size_t i){
		if(i >= _size || i < 0) throw std::out_of_range ("Index out of Bounce Expection");
		for(size_t j=_size; j>i;) _elements[j] = _elements[--j];
		--_size;
	}
	
	

};

/* write to stream */
template <class T>
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
