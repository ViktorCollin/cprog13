.PHONY: all, clean
PROG_NAME := TheLionKingSaga
CPP_SRCS := $(wildcard character/*.cpp) $(wildcard environment/*.cpp) $(wildcard item/*.cpp)
CPP_OBJS := ${CPP_SRCS:.cpp=.o}
CC := g++-4.8
CPPFLAGS := -O2 -std=c++11
SHELL := /bin/bash

all: $(PROG_NAME)
	./$(PROG_NAME)

$(PROG_NAME): main.cpp $(CPP_OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^

clean:
	@- rm -rf $(PROG_NAME)
	@- rm -rf $(CPP_OBJS)

%.o: %.cpp %.h
	$(CC) $(CPPFLAGS) -c $< -o $@
