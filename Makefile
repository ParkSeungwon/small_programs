CFLAG = -std=c++11
GTKCFLAG = $(shell pkg-config gtkmm-3.0 --cflags)
GTKLIB = $(shell pkg-config gtkmm-3.0 --libs)
CC = g++
SRC = $(wildcard *.cc)
EXE = $(patsubst %.cc, %, $(SRC))

all : $(EXE)

rotate : rotate.cc
	$(CC) rotate.cc -o rotate $(GTKCFLAG) $(GTKLIB) $(CFLAG) -g

filefind : filefind.cc
	$(CC) filefind.cc -o filefind $(CFLAG) 

% : %.cc
	$(CC) $< -o $@ $(CFLAG) 
