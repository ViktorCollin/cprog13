compiler = g++
cflags   = -std=c++0x
cxxpath  = cxxtest/
SHELL   := /bin/bash
tests    = unittest.h

runner.cpp:
	python $(cxxpath)cxxtestgen.py --error-printer -o runner.cpp $(tests)

Date.o: Date.h Date.cpp
	$(compiler) $(cflags) -c $^

runtest0%: runner.cpp Date.o
	$(compiler) $(cflags) -I $(cxxpath) -o $@ $^

run0%: runtest0%
	./runtest0$*

submit:
	cp vector.h kth_cprog_vektor.cpp
	submit.py kth_cprog_vektor.cpp
	rm kth_cprog_vektor.cpppyt
