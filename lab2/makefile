compiler = g++
cflags   = -g -O2 -static -std=gnu++0x
cxxpath  = cxxtest/
SHELL   := /bin/bash
tests    = unittest.h calTest.h

runner.cpp: $(tests)
	python $(cxxpath)cxxtestgen.py --error-printer -o $@ $(tests)

date.o: date.h date.cpp
	$(compiler) $(cflags) -c $^

gregorian.o: gregorian.h gregorian.cpp
	$(compiler) $(cflags) -c $^

julian.o: julian.h julian.cpp
	$(compiler) $(cflags) -c $^

middle.o: middle.h middle.cpp
	$(compiler) $(cflags) -c $^

kattistime.o: kattistime.h kattistime.cpp
	$(compiler) $(cflags) -c $^

runtest: julian.o gregorian.o date.o middle.o kattistime.o calendar.h runner.cpp 
	$(compiler) $(cflags) -I $(cxxpath) -o $@ $^

run: runtest
	./runtest
	rm runtest

testa: julian.o gregorian.o date.o middle.o kattistime.o cprog09lab22a.o 
	$(compiler) $(cflags) -o $@ $^
	./testa < lab22a.in | diff lab22a.out - -y --suppress-common-lines
	rm testa

testc: julian.o gregorian.o date.o middle.o kattistime.o cprog11lab22c.o 
	$(compiler) $(cflags) -o $@ $^
	./testc < lab22b.in | diff lab22c.out - -y --suppress-common-lines
	rm testc

clean:
	rm *.o
	rm runner.cpp


submit:
	submit.py julian.h julian.cpp gregorian.h gregorian.cpp meddle.h middle.cpp date.h date.cpp kattistime.h kattistime.cpp cprog09lab22a.cpp 

