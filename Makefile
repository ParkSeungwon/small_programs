CFLAG = -g -std=c++11 -lpthread
GTKCFLAG = $(shell pkg-config gtkmm-3.0 --cflags)
GTKLIB = $(shell pkg-config gtkmm-3.0 --libs)
CC = g++
SRC = $(wildcard *.cc)
EXE = $(patsubst %.cc, %.x, $(SRC))

all : $(EXE)

rotate : rotate.cc
	$(CC) rotate.cc -o rotate $(GTKCFLAG) $(GTKLIB) $(CFLAG) -g

filefind : filefind.cc
	$(CC) filefind.cc -o filefind $(CFLAG) 

%.x : %.cc
	$(CC) $< -o $@ $(CFLAG)
#	./$@

clean:
	rm $(EXE)
