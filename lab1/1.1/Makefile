# Change these
cxxtestpath = ../cxxtest/
testcode    = example_test.h
compiler    = g++-4.8
cflags      = -std=c++11

testcode.cpp: $(testcode)
	python $(cxxtestpath)cxxtestgen.py --error-printer -o testcode.cpp $(testcode)

runtest0%: testcode.cpp Matrix.h
	$(compiler) $(cflags) -I $(cxxtestpath) -o $@ $^

run0%: runtest0%
	./runtest0$*

clean:
	touch runtest0* testcode.cpp
	rm runtest0* testcode.cpp

