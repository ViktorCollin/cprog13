#ifndef VECTOR_H
#define VECTOR_H

#include <initializer_list>
#include <iostream>

using namespace std;
class Vector{
private:
	unsigned int* _elements;
	size_t _size;

public:
	Vector(); 
	explicit Vector(size_t);
	Vector(const Vector&);
	Vector(Vector&&);
	Vector(initializer_list<unsigned int>);
	~Vector();

	Vector& operator=(const Vector&);
	Vector& operator=(Vector&&);
	Vector& operator=(initializer_list<unsigned int>);

	unsigned int& operator[](const unsigned int);
	unsigned int& operator[](const unsigned int) const;

	size_t size() const;
	

};

// cout << "v: " <<  v << " and its size is: " << v.size()
ostream& operator<<(ostream& os, const Vector &v);


#endif
