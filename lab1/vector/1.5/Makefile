tests.o: testcases.cpp vector.h
	g++-4.8 -std=c++11 -g -Wall testcases.cpp vector.h -o tests.o

clean:
	rm *.o
	rm -r *.dSYM

test_template.o: test_template_vec.cpp vector.h 
	g++-4.8 -std=c++11 -g -Wall test_template_vec.cpp vector.h -o test_template.o

ansjo:
	python ../../cxxtest/cxxtestgen.py --error-printer -o runner.cpp ansjo.h
	g++-4.8 -std=c++11 -I../../cxxtest/ -o runner runner.cpp vector.h
	./runner
	rm runner
	rm runner.cpp

test:
	python ../../cxxtest/cxxtestgen.py --error-printer -o runner.cpp ourTestCases.h
	g++-4.8 -std=c++11 -I../../cxxtest/ -o runner runner.cpp vector.h
	./runner
	rm runner
	rm runner.cpp
