compiler = g++-4.8
cflags   = -Wall -std=c++11
cxxpath  = cxxtest/
SHELL   := /bin/bash
tests    = unittest.h calTest.h

runner.cpp: $(tests)
	python $(cxxpath)cxxtestgen.py --error-printer -o $@ $(tests)

Date.o: Date.h Date.cpp
	$(compiler) $(cflags) -c $^

Gregorian.o: Gregorian.h Gregorian.cpp
	$(compiler) $(cflags) -c $^

Julian.o: Julian.h Julian.cpp
	$(compiler) $(cflags) -c $^

Middle.o: Middle.h Middle.cpp
	$(compiler) $(cflags) -c $^

kattistime.o: kattistime.h kattistime.cpp
	$(compiler) $(cflags) -c $^

runtest: Gregorian.o Date.o Middle.o kattistime.o Calendar.h runner.cpp 
	$(compiler) $(cflags) -I $(cxxpath) -o $@ $^

run: runtest
	./runtest

test: Julian.o Gregorian.o Date.o Middle.o kattistime.o cprog09lab22b.o 
	$(compiler) $(cflags) -o $@ $^
	./test

clean:
	rm *.o

submit:
	cp vector.h kth_cprog_vektor.cpp
	submit.py kth_cprog_vektor.cpp
	rm kth_cprog_vektor.cpppyt
