CFLAGS = -Wall -fpic -coverage -lm

default: all

all: testme.c
	gcc -o testme testme.c -g  $(CFLAGS)
