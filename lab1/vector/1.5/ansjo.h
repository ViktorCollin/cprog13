
#ifndef CPROG12_LAB1_VECTOR_TEST_H
#define CPROG12_LAB1_VECTOR_TEST_H



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
		template <class T>
		void assertVectorsEqual(const Vector<T> &a, const Vector<T> &b) {
			TS_ASSERT_EQUALS(a.size(), b.size());
			for (unsigned int i = 0; i < a.size(); ++i) {
				TS_ASSERT_EQUALS(a[i], b[i]);
			}
		}

		void testInitializerList(void) {
			Vector<int> v = {1, 2, 3, 4, 5, 6, 9};
			TS_ASSERT(v[2] == 3);
			v = {1,2};
			TS_ASSERT_EQUALS(v.size(), 2);
			Vector<std::string> v2 = {"1", "2", "3", "4", "5", "6", "9"};
			TS_ASSERT_EQUALS(v2[2], "3");
			v2 = {"1","2"};
			TS_ASSERT_EQUALS(v2.size(), 2);
		}
		
		void testAssignment(void) {
			Vector<int> v = {1, 2, 3, 4, 5, 6, 9};
			v[2] = 42;
			TS_ASSERT(v[2] == 42);
			Vector<std::string> v2 = {"1", "2", "3", "4", "5", "6", "9"};
			v2[2] = "42";
			TS_ASSERT_EQUALS(v2[2], "42");
		}
		
		void testCopyConstructor() {
			Vector<int> v = {1, 2, 3, 4, 5, 6, 9};
			Vector<int> v2 = v;
			assertVectorsEqual(v,v2);
			Vector<std::string> v3 = {"1", "2", "3", "4", "5", "6", "9"};
			Vector<std::string> v4 = v3;
			assertVectorsEqual(v3,v4);
		}
		
		void testDefaultConstructor() {
			Vector<std::string> v(10, "hello");
			TS_ASSERT_EQUALS(v[5], "hello");
		}
		
		void testCopyByValue() {
			Vector<int> v = {1, 2, 3, 4, 5, 6, 9};
			Vector<int> v2 = {5,6,7};
			v = v2;
			assertVectorsEqual(v,v2);
		}
		
		void testScopeStuff() {
			Vector<int> v = {1, 2, 3, 4, 5, 6, 9};
			do{
				Vector<int> v2 = v;
				assertVectorsEqual(v,v2);
				v2.push_back(5);
			} while(false);
			TS_ASSERT_EQUALS(v.size(), 7);
		}
		
		void testThrowingRangeException(void) {
			Vector<int> v = {1,2,4};
			TS_ASSERT_THROWS(v[3], std::out_of_range);
		}
		
		void testPushBack() {
			Vector<int> v = {99, -1, 4711};
			v.push_back(42);
			v.push_back(2);
			v.push_back(7);
			TS_ASSERT_EQUALS(v[3], 42);
			TS_ASSERT_THROWS(v[6], std::out_of_range);

			Vector<float> floatv;
			floatv.push_back(3.14);
			floatv.push_back(2.5);
			TS_ASSERT_EQUALS(floatv.size(), 2);
			TS_ASSERT_DELTA(3.14, floatv[0], 1e-3);
			TS_ASSERT_DELTA(2.5, floatv[1], 1e-3);

			Vector<float> f2 = floatv;
			f2.push_back(-1.0);
			TS_ASSERT_EQUALS(f2.size(), 3);
			TS_ASSERT_EQUALS(floatv.size(), 2);
			TS_ASSERT_DELTA(-1.0, f2[2], 1e-3);
		}
		
		
		void testDefaultInitializer(void) {
			Vector<double> doubles(25, 3.14); 
			for (int i = 0; i < 25; ++i) {
				TS_ASSERT_DELTA(3.14, doubles[i], 1e-3);
			}
			TS_ASSERT_EQUALS(doubles.size(), 25);
		}
		
		void testInsert(void) {
			Vector<int> v = {4711, 17};
			v.insert(0, 42);
			TS_ASSERT_EQUALS(v.size(), 3);
			TS_ASSERT_EQUALS(v[0], 42);
			TS_ASSERT_EQUALS(v[1], 4711);
			TS_ASSERT_EQUALS(v[2], 17);

			Vector<int> v2 = {-1, 0, -1};
			v2.insert(1, 42);
			Vector<int> expected = {-1, 42, 0, -1};
			assertVectorsEqual(v2, expected);

			TS_ASSERT_THROWS(v.insert(-1, 4711), std::out_of_range);
			TS_ASSERT_THROWS(v.insert(1 << 16, 4711), std::out_of_range);
		}
		
		void testInsertThrows() {
			Vector<int> v;
			TS_ASSERT_THROWS(v.insert(1, 17), std::out_of_range);
		}
		
		
		void testClear() {
			Vector<int> v = {1,2,3};
			Vector<int> empty;
			v.clear();
			assertVectorsEqual(v, empty);
		}
		
		void testErase() {
			Vector<int> v = {1};
			Vector<int> empty;
			v.erase(0);
			assertVectorsEqual(v, empty);

			Vector<int> v2 = {1,2,3};
			Vector<int> expected = {1,3};
			v2.erase(1);
			assertVectorsEqual(v2, expected);
			v2.erase(0);
			v2.erase(0);
			assertVectorsEqual(v2,empty);
		}
		
		void testEraseLast() {
			Vector<int> v = {42, 47, -4711}, empty;
			v.erase(2);
			Vector<int> expected = {42, 47};
			assertVectorsEqual(v, expected);
		}
		
		void testSortEmpty() {
			Vector<int> e;
			e.sort();
			Vector<int> expected;
			assertVectorsEqual(e, expected);
		}
		
		void testSortOneElement() {
			Vector<int> v = {1337}, expected = {1337};
			v.sort();
			assertVectorsEqual(v, expected);
		}
		
		void testSortTwoElements() {
			Vector<int> v = {1337, 0}, expected = {0, 1337};
			v.sort();
			assertVectorsEqual(v, expected);
		}
		
		
		void testSortElevenElements() {
			Vector<int> v = 	{-1, 0, 5, 3, 8, 7, 6, 9, 2, 4, 1}, 
				expected = 		{-1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
			v.sort();
			assertVectorsEqual(v, expected);
		}
		
		void testSortStrings() {
			Vector<string> v = {"apple", "fox", "banana", "test"},
				expected = {"apple", "banana", "fox", "test"};
			v.sort();
			assertVectorsEqual(v, expected);
		}

		void testEmptyContains() {
			Vector<string> v = {};
			TS_ASSERT_EQUALS(false, v.exists("foo"));
		}
		
		void testSortThreeElementsAsc() {
			Vector<int> v = {1, 3, 2}, expected = {1, 2, 3};
			v.sort();
			assertVectorsEqual(v, expected);
		}

		void testSortThreeElementsDesc() {
			Vector<int> v = {1, 3, 2}, expected = {3,2,1};
			v.sort(false);
			assertVectorsEqual(v, expected);
		}
		
	
		
		
		void testWithClasses() {
			Vector<Foo> v;
			Foo f;
			v.push_back(f);
			f.x = 5;
			TS_ASSERT_DIFFERS(v[0].x, f.x);
		}
		
		void testInsertAtNegativeIndex() {
			Vector<int> v = {1, 2, 3};
			TS_ASSERT_THROWS(v.erase(-1), std::out_of_range); 
		}
		
		void testCopyEmpty() {
			Vector<int> v, empty;
			Vector<int> v2 = {0, 1, 2};
			v2 = v;

			assertVectorsEqual(v2, empty);

			v = {};

		}
		
		void testLotsOfPushbacks() {
			Vector<int> v(100, 42);
			const int size = 10000;
			for(int i = 0; i < size; ++i) {
				v.push_back(i);
			}

			for (int i = 0 ; i < 100; ++i) {
				TS_ASSERT_EQUALS(42, v[i]);
			}

			for (int i = 100; i < 10100; ++i) {
				TS_ASSERT_EQUALS(i - 100, v[i]);
			}

		}
		
		void testLotsOfErases() {
			Vector<std::string> v(1000, "hello"), empty;

			for (int i = 0; i < 1000 -1; ++i) {
				v.erase(1);
			}
			assertVectorsEqual({"hello"}, v);
		}
		
		void testLotsOfInserts() {
			Vector<float> fs;
			for (int i = 0; i < 1000; ++i) {
				fs.insert(0, 0.5);
			}

			for (int i = 0; i < 1000; ++i) {
				TS_ASSERT_DELTA(fs[i], 0.5, 0.001);
			}
		}
		
		void testContainsOneElem() {
			Vector<string> v = { "foo"};
			TS_ASSERT_EQUALS(true, v.exists("foo"));
			TS_ASSERT_EQUALS(false, v.exists("bar"));
		}
		
		void testContainsTwoElems() {
			Vector<string> v = { "foo", "bar"};
			TS_ASSERT_EQUALS(true, v.exists("foo"));
			TS_ASSERT_EQUALS(true, v.exists("bar"));
			TS_ASSERT_EQUALS(false, v.exists("baz"));
		}
		
		
		void testContainsTwoElemsWithErase() {
			Vector<string> v = { "foo", "bar"};
			TS_ASSERT_EQUALS(true, v.exists("foo"));
			TS_ASSERT_EQUALS(true, v.exists("bar"));
			TS_ASSERT_EQUALS(false, v.exists("baz"));
			v.erase(1);
			TS_ASSERT_EQUALS(false, v.exists("bar"));
		}
		
		void testInsertWithClasses() {
			Vector<Foo> v(2);
			Foo f;
			v.insert(0, f);
			f.x = 5;
			TS_ASSERT_DIFFERS(v[0].x, f.x);
		}
		
		void testInsertWithStandardVector() {
			std::vector<Foo> v(2);
			Foo f;
			v[0] = f;
			f.x = 5;
			TS_ASSERT_DIFFERS(v[0].x, f.x);
		}
		
		void testStdMoveingObjects() {
			Vector<Foo> v(10);
			v[2].x = -1;
			Vector<Foo> expected = v;
			Vector<Foo> v2 = std::move(v);
			Vector<Foo> v3;
			TS_ASSERT_EQUALS(10, v2.size());
			TS_ASSERT_EQUALS(0, v.size());
			v3 = std::move(v2);
			TS_ASSERT_EQUALS(10, v3.size());
			TS_ASSERT_EQUALS(0, v2.size());

			assertVectorsEqual(v3, expected);
			TS_ASSERT_EQUALS(v3[2].x, -1);
		}
		
		void testErasingObjects() {
			Vector<Foo> objects(3);
			Vector<Foo> expected(2);
			cout << "\nobj: " << objects << endl;
			objects[1].x = -1;
			cout << "obj: " << objects << endl;
			objects.erase(1);
			cout << "obj: " << objects << endl;

			assertVectorsEqual(expected, objects);
		}
		
		void testDefaultVal() {
			Vector<std::string> strs(2), expected = {"", ""};
			assertVectorsEqual(strs, expected);

			Vector<int> ints(100);
			for (int i = 0; i < 100; ++i) {
				TS_ASSERT_EQUALS(0, ints[i]);
			}
		}

		void TestFirstPart() {
			Vector<int> v(1);
			TS_ASSERT_EQUALS(v[0], 0);
			TS_ASSERT_EQUALS(v.size(), 1);
		}
	
		

		
		


};



#endif
