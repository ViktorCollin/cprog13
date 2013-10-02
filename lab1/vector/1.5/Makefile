compiler = g++
cflags   = -std=c++0x
SHELL := /bin/bash

tests.o: testcases.cpp vector.h
	$(compiler) $(cflags) -g -Wall testcases.cpp vector.h -o tests.o

clean:
	rm *.o
	rm -r *.dSYM

test_template.o: test_template_vec.cpp vector.h 
	$(compiler) $(cflags) -g -Wall test_template_vec.cpp vector.h -o test_template.o

ansjo:
	python ../../cxxtest/cxxtestgen.py --error-printer -o runner.cpp ansjo.h
	$(compiler) $(cflags) -I../../cxxtest/ -o runner runner.cpp vector.h
	./runner
	rm runner
	rm runner.cpp

test:
	python ../../cxxtest/cxxtestgen.py --error-printer -o runner.cpp ourTestCases.h
	$(compiler) $(cflags) -I../../cxxtest/ -o runner runner.cpp vector.h
	./runner
	rm runner
	rm runner.cpp

submit:
	cp vector.h kth_cprog_vektor.cpp
	submit.py kth_cprog_vektor.cpp
	rm kth_cprog_vektor.cpp
