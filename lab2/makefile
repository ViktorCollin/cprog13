compiler = g++-4.8
cflags   = -std=c++11
cxxpath  = cxxtest/
SHELL   := /bin/bash
tests    = unittest.h

runner.cpp: $(tests)
	python $(cxxpath)cxxtestgen.py --error-printer -o $@ $(tests)

Date.o: Date.h Date.cpp
	$(compiler) $(cflags) -c $^

runtest0%: Date.o runner.cpp 
	$(compiler) $(cflags) -I $(cxxpath) -o $@ $^

run0%: runtest0%
	./runtest0$*

submit:
	cp vector.h kth_cprog_vektor.cpp
	submit.py kth_cprog_vektor.cpp
	rm kth_cprog_vektor.cpppyt
