CC=g++
CSRC:=./*.cpp
LIBFLAGS:= --mode=link $(CC) `pkg-config --cflags --libs gstreamer-0.10` -o scumb
LIBFLAGS_TESTING:= --mode=link $(CC) `pkg-config --cflags --libs gstreamer-0.10` -o scumb -ggdb -Wall

all: scumb

scumb: 
	libtool $(LIBFLAGS) *.cpp

testing: clean
	libtool $(LIBFLAGS_TESTING) *.cpp

clean: 
	@rm -vf *.o scumb core*
