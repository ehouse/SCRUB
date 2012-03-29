CC=gcc
CSRC:=./*.cpp
LIBFLAGS:= --mode=link $(CC) `pkg-config --cflags --libs gstreamer-0.10` -o qcmp
LIBFLAGS_TESTING:= --mode=link $(CC) `pkg-config --cflags --libs gstreamer-0.10` -o qcmp -ggdb -Wall

all: qcmp

qcmp: 
	libtool $(LIBFLAGS) *.cpp

testing: clean
	libtool $(LIBFLAGS_TESTING) *.cpp

clean: 
	@rm -vf *.o qcmp core*
