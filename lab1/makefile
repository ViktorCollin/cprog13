%.out:	%.cpp
	g++-4.8 -g -std=c++0x -Wall $*.cpp -o $*.out
	
test: 
	g++-4.8 -c must_follow_a.cpp
	cxxtest/cxxtestgen.py --error-printer -o 1.2b.cpp test_must_follow_a.cpp	
	g++ -o test_1.2b.out -I cxxtest/ 1.2b.cpp must_follow_a.o
	./test_1.2b.out
