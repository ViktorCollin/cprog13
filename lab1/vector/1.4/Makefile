tests.o: testcases.cpp vector.h vector.cpp 
	g++-4.8 -std=c++11 -g -Wall testcases.cpp vector.h vector.cpp -o tests.o

clean:
	rm *.o
	rm -r *.dSYM

test_vec.o: test_vec.cpp vector.h vector.cpp
	g++-4.8 -std=c++11 -g -Wall test_vec.cpp vector.h vector.cpp -o test_vec.o
