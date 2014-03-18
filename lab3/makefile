NAME := TheLionKingSaga
CPP_SRCS := $(wildcard *.cpp)
CPP_OBJS := ${CPP_SRCS:.cpp=.o}
CC = g++-4.8
CPPFLAGS = -O2 -std=c++11
SHELL	:= /bin/bash

all: $(NAME)

$(NAME):
	$(CC) $(CPPFLAGS) $(CPP_OBJS) -o $(NAME)

clean:
    @- rm -rf $(program_NAME)
    @- rm -rf $(program_OBJS)

define OBJECT_DEPENDS_ON_CORRESPONDING_HEADER
    $(1) : ${1:.o=.h}
endef

$(foreach object_file,$(CPP_OBJS),$(eval $(call OBJECT_DEPENDS_ON_CORRESPONDING_HEADER,$(object_file))))

