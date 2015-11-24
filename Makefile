#	Dan Wilder
#	
#	University of Missouri - St. Louis
#	CS 3130 - Design & Analysis of Algorithms
#	Galina Piatnitskiaia (instructor)
#	Project #3
#	
#	Makefile

 
CC=gcc
CFLAGS=-g -Wall

HEADERS=tree.h

SOURCES_A=part_a.c tree.c

OBJECTS_A=$(SOURCES_A:.c=.o)

EXECUTABLE_A=run_A

all: $(EXECUTABLE_A)

$(EXECUTABLE_A): $(OBJECTS_A)  
	$(CC) $(OBJECTS_A) -o $(EXECUTABLE_A) -lm

%.o: %.c $(HEADERS)
	$(CC) -c $(CFLAGS) $*.c -o $*.o
	
.PHONY: clean

clean:
	rm *.o $(EXECUTABLE_A)