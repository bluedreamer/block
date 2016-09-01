CPP=clang++
CC=clang
TARGET=$(shell basename $(shell pwd))
INCLUDE=
CPPFLAGS=-std=c++14 -ggdb3 -MD ${INCLUDE} 
SOURCE=$(shell ls *.cpp)
#HEADERS=${shell ls *.h}
OBJS=${SOURCE:.cpp=.o}

${TARGET}: main.o ${OBJS} ${HEADERS}
	$(CXX) -o $@ $^

install:
	cp ${TARGET} ~/bin

clean:
	rm -f *.[do] ${TARGET} core.*
