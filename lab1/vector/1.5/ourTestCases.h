
#ifndef CPROG13_LAB1_VECTOR_TEST_H
#define CPROG13_LAB1_VECTOR_TEST_H



#include <utility>
#include <cxxtest/TestSuite.h>
#include "vector.h"
#include <stdexcept>
#include <string>
#include <vector>
#include <iostream>


struct Foo {
	int x, y;
	std::string str;

	Foo() : x(1), y(2), str("hello") {}
	Foo(int _x, int _y, std::string _str) : x(_x), y(_y), str(_str) {}

	bool operator==(const Foo & ref) {
		return x == ref.x && y == ref.y && str == ref.str;
	}
	

};
ostream& operator<<(ostream &os, const Foo &f){
	os << "{" << f.x << ", " << f.y << ", " << f.str << "}";
	return os;
}
class SomeTest : public CxxTest::TestSuite {

	public:
		template <typename T>
		void assertVectorsEqual(const Vector<T> &a, const Vector<T> &b) {
			TS_ASSERT_EQUALS(a.size(), b.size());
			for (std::size_t i = 0; i < a.size(); ++i) {
				TS_ASSERT_EQUALS(a[i], b[i]);
			}
		}

		// void testDefaultConstructor(){
		// 			Vector<int> vInt();
		// 			TS_ASSERT_EQUALS(vInt.size(), 0);
		// 			TS_ASSERT_EQUALS(vInt.maxSize(), DEFAULT_INIT_SIZE);
		// 			Vector<std::string> vString();
		// 			TS_ASSERT_EQUALS(vString.size(), 0);
		// 			TS_ASSERT_EQUALS(vString.maxSize(), DEFAULT_INIT_SIZE);
		// 			Vector<Foo> vFoo();
		// 			TS_ASSERT_EQUALS(vFoo.size(), 0);
		// 			TS_ASSERT_EQUALS(vFoo.maxSize(), DEFAULT_INIT_SIZE);
		// 		}

		void testSizeZeroConstructor(){
			Vector<int> vInt(0);
			TS_ASSERT_EQUALS(vInt.size(), 0);
			TS_ASSERT_EQUALS(vInt.maxSize(), DEFAULT_INIT_SIZE);
			Vector<std::string> vString(0);
			TS_ASSERT_EQUALS(vString.size(), 0);
			TS_ASSERT_EQUALS(vString.maxSize(), DEFAULT_INIT_SIZE);
			Vector<Foo> vFoo(0);
			TS_ASSERT_EQUALS(vFoo.size(), 0);
			TS_ASSERT_EQUALS(vFoo.maxSize(), DEFAULT_INIT_SIZE);

		}

		void testSizeOneConstructor(){
			Vector<int> vInt(1);
			TS_ASSERT_EQUALS(vInt.size(), 1);
			TS_ASSERT_EQUALS(vInt.maxSize(), DEFAULT_INIT_SIZE);
			//int eInt;
			//TS_ASSERT_EQUALS(vInt[0], eInt);
			Vector<std::string> vString(1);
			TS_ASSERT_EQUALS(vString.size(), 1);
			TS_ASSERT_EQUALS(vString.maxSize(), DEFAULT_INIT_SIZE);
			std::string eString;
			TS_ASSERT_EQUALS(vString[0], eString);
			Vector<Foo> vFoo(1);
			Foo eFoo;
			TS_ASSERT_EQUALS(vFoo.size(), 1);
			TS_ASSERT_EQUALS(vFoo.maxSize(), DEFAULT_INIT_SIZE);
			TS_ASSERT_EQUALS(vFoo[0], eFoo);

		}
		
		void testSizeTwoConstructor(){
			Vector<int> vInt(2);
			TS_ASSERT_EQUALS(vInt.size(), 2);
			TS_ASSERT_EQUALS(vInt.maxSize(), DEFAULT_INIT_SIZE);
			//int eInt;
			//TS_ASSERT_EQUALS(vInt[0], eInt);
			Vector<std::string> vString(2);
			TS_ASSERT_EQUALS(vString.size(), 2);
			TS_ASSERT_EQUALS(vString.maxSize(), DEFAULT_INIT_SIZE);
			std::string eString;
			TS_ASSERT_EQUALS(vString[0], eString);
			TS_ASSERT_EQUALS(vString[1], eString);
			Vector<Foo> vFoo(2);
			Foo eFoo;
			TS_ASSERT_EQUALS(vFoo.size(), 2);
			TS_ASSERT_EQUALS(vFoo.maxSize(), DEFAULT_INIT_SIZE);
			TS_ASSERT_EQUALS(vFoo[0], eFoo);
			TS_ASSERT_EQUALS(vFoo[1], eFoo);

		}
		
		void testSizeSixteenConstructor(){
			Vector<int> vInt(16);
			TS_ASSERT_EQUALS(vInt.size(), 16);
			TS_ASSERT_EQUALS(vInt.maxSize(), DEFAULT_INIT_SIZE);
			Vector<std::string> vString(16);
			TS_ASSERT_EQUALS(vString.size(), 16);
			TS_ASSERT_EQUALS(vString.maxSize(), DEFAULT_INIT_SIZE);
			Vector<Foo> vFoo(16);
			TS_ASSERT_EQUALS(vFoo.size(), 16);
			TS_ASSERT_EQUALS(vFoo.maxSize(), DEFAULT_INIT_SIZE);

		}
		
		void testSizeSeventeenConstructor(){
			Vector<int> vInt(17);
			TS_ASSERT_EQUALS(vInt.size(), 17);
			TS_ASSERT_EQUALS(vInt.maxSize(), 17);
			Vector<std::string> vString(17);
			TS_ASSERT_EQUALS(vString.size(), 17);
			TS_ASSERT_EQUALS(vString.maxSize(), 17);
			Vector<Foo> vFoo(17);
			TS_ASSERT_EQUALS(vFoo.size(), 17);
			TS_ASSERT_EQUALS(vFoo.maxSize(), 17);

		}
		
		void testInitializerListSizeZero(){
			Vector<int> vInt = {};
			TS_ASSERT_EQUALS(vInt.size(), 0);
			TS_ASSERT_EQUALS(vInt.maxSize(), DEFAULT_INIT_SIZE);
			Vector<std::string> vString {};
			TS_ASSERT_EQUALS(vString.size(), 0);
			TS_ASSERT_EQUALS(vString.maxSize(), DEFAULT_INIT_SIZE);
			Vector<Foo> vFoo = {};
			TS_ASSERT_EQUALS(vFoo.size(), 0);
			TS_ASSERT_EQUALS(vFoo.maxSize(), DEFAULT_INIT_SIZE);
		}
		
		void testInitializerListSizeOne(){
			Vector<int> vInt = {1};
			TS_ASSERT_EQUALS(vInt.size(), 1);
			TS_ASSERT_EQUALS(vInt.maxSize(), DEFAULT_INIT_SIZE);
			TS_ASSERT_EQUALS(vInt[0], 1);
			Vector<std::string> vString = {"hej"};
			TS_ASSERT_EQUALS(vString.size(), 1);
			TS_ASSERT_EQUALS(vString.maxSize(), DEFAULT_INIT_SIZE);
			std::string eString("hej");
			TS_ASSERT_EQUALS(vString[0], eString);
		}
		
		void testInitializerListSizeTwo(){
			Vector<int> vInt = {1, 2};
			TS_ASSERT_EQUALS(vInt.size(), 2);
			TS_ASSERT_EQUALS(vInt.maxSize(), DEFAULT_INIT_SIZE);
			TS_ASSERT_EQUALS(vInt[0], 1);
			TS_ASSERT_EQUALS(vInt[1], 2);
			Vector<std::string> vString = {"hej", "hopp"};
			TS_ASSERT_EQUALS(vString.size(), 2);
			TS_ASSERT_EQUALS(vString.maxSize(), DEFAULT_INIT_SIZE);
			TS_ASSERT_EQUALS(vString[0], "hej");
			TS_ASSERT_EQUALS(vString[1], "hopp");
		}
		
		void testSortSizeZero(){
			Vector<int> vInt, expectedInt;
			vInt.sort();
			assertVectorsEqual(vInt, expectedInt);
			TS_ASSERT_EQUALS(vInt.size(), 0);
			TS_ASSERT_EQUALS(vInt.maxSize(), DEFAULT_INIT_SIZE);
			Vector<std::string> vString, expectedString;
			vString.sort();
			assertVectorsEqual(vString, expectedString);
			TS_ASSERT_EQUALS(vString.size(), 0);
			TS_ASSERT_EQUALS(vString.maxSize(), DEFAULT_INIT_SIZE);
		}
		
		void testSortSizeOne(){
			Vector<int> vInt(1), expectedInt(1);
			vInt.sort();
			assertVectorsEqual(vInt, expectedInt);
			TS_ASSERT_EQUALS(vInt.size(), 1);
			TS_ASSERT_EQUALS(vInt.maxSize(), DEFAULT_INIT_SIZE);
			Vector<std::string> vString(1), expectedString(1);
			vString.sort();
			assertVectorsEqual(vString, expectedString);
			TS_ASSERT_EQUALS(vString.size(), 1);
			TS_ASSERT_EQUALS(vString.maxSize(), DEFAULT_INIT_SIZE);
		}
		
		void testSort(){
			Vector<int> vInt = {2,4,1,3}, expectedInt = {1,2,3,4};
			vInt.sort();
			assertVectorsEqual(vInt, expectedInt);
			TS_ASSERT_EQUALS(vInt.size(), 4);
			TS_ASSERT_EQUALS(vInt.maxSize(), DEFAULT_INIT_SIZE);
			Vector<std::string> vString = {"cd", "disk", "analog", "digital"}, 
			expectedString = {"analog", "cd", "digital", "disk"};
			vString.sort();
			assertVectorsEqual(vString, expectedString);
			TS_ASSERT_EQUALS(vString.size(), 4);
			TS_ASSERT_EQUALS(vString.maxSize(), DEFAULT_INIT_SIZE);
		}
		
		void testSortReverseSizeZero(){
			Vector<int> vInt, expectedInt;
			vInt.sort(false);
			assertVectorsEqual(vInt, expectedInt);
			TS_ASSERT_EQUALS(vInt.size(), 0);
			TS_ASSERT_EQUALS(vInt.maxSize(), DEFAULT_INIT_SIZE);
			Vector<std::string> vString, expectedString;
			vString.sort(false);
			assertVectorsEqual(vString, expectedString);
			TS_ASSERT_EQUALS(vString.size(), 0);
			TS_ASSERT_EQUALS(vString.maxSize(), DEFAULT_INIT_SIZE);
		}
		
		void testSortReverseSizeOne(){
			Vector<int> vInt(1), expectedInt(1);
			vInt.sort(false);
			assertVectorsEqual(vInt, expectedInt);
			TS_ASSERT_EQUALS(vInt.size(), 1);
			TS_ASSERT_EQUALS(vInt.maxSize(), DEFAULT_INIT_SIZE);
			Vector<std::string> vString(1), expectedString(1);
			vString.sort(false);
			assertVectorsEqual(vString, expectedString);
			TS_ASSERT_EQUALS(vString.size(), 1);
			TS_ASSERT_EQUALS(vString.maxSize(), DEFAULT_INIT_SIZE);
		}
		
		void testSortReverse(){
			Vector<int> vInt = {2,4,1,3}, expectedInt = {4,3,2,1};
			vInt.sort(false);
			assertVectorsEqual(vInt, expectedInt);
			TS_ASSERT_EQUALS(vInt.size(), 4);
			TS_ASSERT_EQUALS(vInt.maxSize(), DEFAULT_INIT_SIZE);
			Vector<std::string> vString = {"cd", "disk", "analog", "digital"}, 
			expectedString = {"disk", "digital", "cd", "analog"};
			vString.sort(false);
			assertVectorsEqual(vString, expectedString);
			TS_ASSERT_EQUALS(vString.size(), 4);
			TS_ASSERT_EQUALS(vString.maxSize(), DEFAULT_INIT_SIZE);
		}
};



#endif
